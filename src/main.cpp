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

// Temporary definitions
#define FOV glm::radians(ChConstants::VIEW_FOV)
#define ASPECT_RATIO (window.getWidth() * 1.0f) / (window.getHeight() * 1.0f)

int main() {
	Window window(ChConstants::WINDOW_WIDTH, ChConstants::WINDOW_HEIGHT, ChConstants::WINDOW_TITLE);
	ChGraphics::Model model;
	ChIO::Image image("res/tex/test.png");

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
	
	while (!window.shouldClose()) {
		auto now = std::chrono::high_resolution_clock::now();
		float delta = std::chrono::duration_cast<std::chrono::duration<float>>(now - lastTime).count();

		camera.position = glm::vec3(0, 0, sin(delta) + 2);
		objectTransform.rotation = glm::vec3(0, sin(delta*2) * 60, 0);

		glViewport(0, 0, window.getWidth(), window.getHeight());
		glClear(GL_COLOR_BUFFER_BIT);
		
		projectionMatrix = glm::perspective(FOV, ASPECT_RATIO, ChConstants::VIEW_NEARPLANE, ChConstants::VIEW_FARPLANE);
		transformMatrix = ChUtil::createTransformMatrix(objectTransform);
		viewMatrix = ChUtil::createViewMatrix(camera);

		glUniformMatrix4fv(glGetUniformLocation(shader, "u_pMatrix"), 1, false, (const float*)&projectionMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "u_vMatrix"), 1, false, (const float*)&viewMatrix[0][0]);
		glUniformMatrix4fv(glGetUniformLocation(shader, "u_tMatrix"), 1, false, (const float*)&transformMatrix[0][0]);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	ChGraphics::deleteModel(&model);
	glDeleteProgram(shader);
	glDeleteTextures(1, &texture);

	return 0;
}
