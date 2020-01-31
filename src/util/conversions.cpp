#include "conversions.hpp"

FloatColour RGBtoFloats(int rgbColour) {
	// Get the ARGB colour channels out from the colour integer
	int a = rgbColour >> 24 & 0xff;
	int r = rgbColour >> 16 & 0xff;
	int g = rgbColour >> 8 & 0xff;
	int b = rgbColour & 0xff;

	FloatColour result;

	result.r = r / 255.0f;
	result.g = g / 255.0f;
	result.b = b / 255.0f;
	result.a = a / 255.0f;

	return result;
}

glm::mat4 getTransformationMatrix(Transformation source) {
	glm::mat4 matrix = glm::mat4(1.0f);

	matrix = glm::translate(matrix, source.position);
	matrix = glm::rotate(matrix, glm::radians(source.rotation.x), glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, glm::radians(source.rotation.y), glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, glm::radians(source.rotation.z), glm::vec3(0, 0, 1));
	matrix = glm::scale(matrix, source.scale);

	return matrix;
}