#pragma once

#include <string>
#include <iostream>
#include <GL/glew.h>

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