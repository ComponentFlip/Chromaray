#include "Matrix4f.hpp"

#include <math.h>

#define toRadians(x) (x) * 3.14159f / 180.0f

Matrix4f::Matrix4f() {
	setAll(0);
}

void Matrix4f::setAll(float value) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			data[x][y] = value;
		}
	}
}

void Matrix4f::setProjectionMatrix(float aspect, float fov, float farPlane, float nearPlane) {
	float yScale = (1.0f / tan(toRadians(fov / 2.0f)) * aspect);
	float xScale = yScale / aspect;
	float frustumLength = farPlane - nearPlane;

	data[0][0] = xScale;
	data[1][1] = yScale;
	data[2][2] = -((farPlane + nearPlane) / frustumLength);
	data[2][3] = -1;
	data[3][2] = -((2 * nearPlane * farPlane) / frustumLength);
	data[3][3] = 0;
}