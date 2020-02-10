#include <GL/glew.h>
#include <iostream>

#include "Shader.hpp"

static int loadShader(const char* source, int type);

int ChGraphics::createShaderProgram(const char* vertexSource, const char* fragmentSource) {
	int vertexShader = loadShader(vertexSource, GL_VERTEX_SHADER);
	int fragmentShader = loadShader(fragmentSource, GL_FRAGMENT_SHADER);

	int program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	int linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
		int length;
		char message[512];

		glGetShaderInfoLog(program, 512, &length, message);
		std::cerr << "Could not link program!\n" << message << std::endl;
	}

	return program;
}

static int loadShader(const char* source, int type) {
	int shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	int compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (!compiled) {
		int length;
		char message[512];

		glGetShaderInfoLog(shader, 512, &length, message);
		std::cerr << "Could not compile shader!\n" << message << std::endl;
	}

	return shader;
}