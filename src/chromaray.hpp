#pragma once

#include <string>

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