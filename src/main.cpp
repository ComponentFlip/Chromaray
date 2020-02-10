#include <gl/glew.h>

#include <iostream>

#include "Window.hpp"
#include "FileReader.hpp"
#include "gfx/Shader.hpp"

int main() {
	Window window(640, 480, "Chromaray");

	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f 
	};

	unsigned indices[] = {
		0, 1, 2,
		2, 3, 0 
	};

	unsigned vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), vertices, GL_STATIC_DRAW);

	unsigned indexBuffer;
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned), indices, GL_STATIC_DRAW);

	unsigned vertexArray;
	glGenVertexArrays(1, &vertexArray);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

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

	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
	glDeleteVertexArrays(1, &vertexArray);
	glDeleteProgram(shader);

	return 0;
}
