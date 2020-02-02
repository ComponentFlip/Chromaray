#pragma once

#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../chromaray.hpp"

struct FloatColour {
	float r;
	float g;
	float b;
	float a;
};

FloatColour RGBtoFloats(int rgbColour);

glm::mat4 getTransformationMatrix(Transformation source);
glm::mat4 getViewMatrix(Transformation source);