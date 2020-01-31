#pragma once

class Matrix4f {
public:
	Matrix4f();

	void setAll(float value);
	void setProjectionMatrix(float aspect, float fov, float farPlane, float nearPlane);

	float data[4][4];
};
