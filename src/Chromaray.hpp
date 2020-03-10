#pragma once

namespace ChConstants {
	constexpr int WINDOW_WIDTH = 640;
	constexpr int WINDOW_HEIGHT = 480;
	constexpr const char* WINDOW_TITLE = "Chromaray";

	constexpr float VIEW_FOV = glm::radians(75.0f);
	constexpr float VIEW_NEARPLANE = 0.001f;
	constexpr float VIEW_FARPLANE = 100.0f;

	constexpr int SHADER_ERRORLENGTH = 512;

	constexpr float PLAYER_MOVE_SPEED = 0.04f;
	constexpr float PLAYER_TURN_SPEED = 2.f;
}