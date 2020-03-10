#pragma once

#include "glm/glm.hpp"

namespace ChGraphics {
	int createShaderProgram(const char* vertexSource, const char* fragmentSource);

	void storeMatrix(int shaderID, glm::mat4& matrix, const char* locationName);
}