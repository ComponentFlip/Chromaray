#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>
#include <chrono>

#include "Chromaray.hpp"

#include "Window.hpp"
#include "FileReader.hpp"
#include "util/Conversions.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"
#include "gfx/Texture.hpp"

#include "Player.hpp"

#define GET_FOV(width, height) glm::perspective(ChConstants::VIEW_FOV, (width * 1.0f) / (height * 1.0f), ChConstants::VIEW_NEARPLANE, ChConstants::VIEW_FARPLANE)

int main() {
	ChCore::createWindow({ChConstants::WINDOW_WIDTH, ChConstants::WINDOW_HEIGHT, ChConstants::WINDOW_TITLE});
	ChGraphics::Model model;
	ChIO::Image image("res/tex/test.png");

	Player player;

	ChUtil::Transform objectTransform;
	ChUtil::Transform camera;
	camera.position = glm::vec3(0, 0, 2);

	glm::mat4 projectionMatrix;
	glm::mat4 transformMatrix;
	glm::mat4 viewMatrix;
	
	model.vertices = {
		// POSITIONS         RGB COLOURS      TEX COORDS
		-0.5f, -0.5f, 0.f,   1.f, 0.f, 0.f,   0.f, 0.f,
		 0.5f, -0.5f, 0.f,   0.f, 1.f, 0.f,   1.f, 0.f,
		 0.5f,  0.5f, 0.f,   0.f, 0.f, 1.f,   1.f, 1.f,
		-0.5f,  0.5f, 0.f,   1.f, 0.f, 1.f,   0.f, 1.f
	};

	model.indices = {
		0, 1, 2,
		2, 3, 0 
	};
	
	ChGraphics::storeModel(&model);

	int shader = ChGraphics::createShaderProgram(
		ChIO::readTextFile("res/glsl/shader.vert").c_str(), 
		ChIO::readTextFile("res/glsl/shader.frag").c_str()
	);

	unsigned texture = ChGraphics::loadTexture(image.getWidth(), image.getHeight(), image.getPixels());

	glUseProgram(shader);

	// Temporary timing code
	auto lastTime = std::chrono::high_resolution_clock::now();
	
	do {
		auto now = std::chrono::high_resolution_clock::now();
		float delta = std::chrono::duration_cast<std::chrono::duration<float>>(now - lastTime).count();

		player.update(camera);
		
		// Get window properties for use later.
		ChCore::WindowProperties* prop = new ChCore::WindowProperties();
		*prop = ChCore::getWindowProperties();

		// Prepare OpenGL for rendering a frame.
		glViewport(0, 0, prop->width, prop->height);
		glClear(GL_COLOR_BUFFER_BIT);

		// Set the matrices.
		projectionMatrix = GET_FOV(prop->width, prop->height);
		transformMatrix = ChUtil::createTransformMatrix(objectTransform);
		viewMatrix = ChUtil::createViewMatrix(camera);

		// Store matrices into the shader.
		ChGraphics::storeMatrix(shader, projectionMatrix, "u_pMatrix");
		ChGraphics::storeMatrix(shader, viewMatrix, "u_vMatrix");
		ChGraphics::storeMatrix(shader, transformMatrix, "u_tMatrix");
		
		// Draws the quad.
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		delete prop;

	} while (ChCore::updateWindow()); // Game loop will exit if the window should close

	glDeleteProgram(shader);
	glDeleteTextures(1, &texture);

	ChGraphics::deleteModel(&model);
	ChCore::destroyWindow();

	return 0;
}
