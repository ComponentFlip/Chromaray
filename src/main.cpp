#include <gl/glew.h>

#include <iostream>
#include <vector>

#include "../libs/stb_image.h"
#include "Chromaray.hpp"

#include "Window.hpp"
#include "FileReader.hpp"
#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"

int main() {
	Window window(ChConstants::WINDOW_WIDTH, ChConstants::WINDOW_HEIGHT, ChConstants::WINDOW_TITLE);
	ChGraphics::Model model;

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

	glUseProgram(shader);

	while (!window.shouldClose()) {
		glViewport(0, 0, window.getWidth(), window.getHeight());
		glClear(GL_COLOR_BUFFER_BIT);
		
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	ChGraphics::deleteModel(&model);
	glDeleteProgram(shader);

	return 0;
}
