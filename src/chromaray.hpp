#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>
#include <iostream>

// GL error debugging
#define GLCALL(x) x; clearGLerror(__FILE__, __LINE__)
static const char* convertGLerrorToString(const GLenum error);
static void clearGLerror(const char* file, int line);

namespace Constants {
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	const std::string WINDOW_TITLE = "Chromaray";

	const std::string SHADER_PATH = "res/glsl/";
	const int SHADER_ERROR_SIZE = 1024;

	const int VERTEXARRAY_POSITION_POINTER = 0;

	const float SCENE_FOV = 75.0f;
	const float SCENE_NEARPLANE = 0.001f;
	const float SCENE_FARPLANE = 100.0f;
}

struct Transformation {
	Transformation()
		: position(glm::vec3(0, 0, 0))
		, rotation(glm::vec3(0, 0, 0))
		, scale(glm::vec3(1, 1, 1)) {}

	void setPosition(float x, float y, float z) { position = glm::vec3(x, y, z); }
	void setRotation(float x, float y, float z) { rotation = glm::vec3(x, y, z); }
	void setScale(float x, float y, float z) { scale = glm::vec3(x, y, z); }

	glm::vec3 position, rotation, scale;
};

static const char* convertGLerrorToString(const GLenum error) {
	switch (error) {
		case GL_INVALID_ENUM:
			return "GL_INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			return "GL_INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			return "GL_INVALID_OPERATION";
			break;
		case GL_STACK_OVERFLOW:
			return "GL_STACK_OVERFLOW";
			break;
		case GL_STACK_UNDERFLOW:
			return "GL_STACK_UNDERFLOW";
			break;
		case GL_OUT_OF_MEMORY:
			return "GL_OUT_OF_MEMORY";
			break;
		default:
			return "UNKNOWN";
	}
}

static void clearGLerror(const char* file, int line) {
	GLenum error;
	while ((error = glGetError()) != GL_NO_ERROR) {
		printf("GL ERROR [%s:%i]: %x (%s)\n", file, line, error, convertGLerrorToString(error));
	}
}