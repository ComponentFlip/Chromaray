#pragma once

#include "gfx/Shader.hpp"
#include "util/Matrix4f.hpp"

class Scene {
public:
	Scene(const int width, const int height, const Shader& shader);

	void update(const int width, const int height);
private:
	Matrix4f m_ProjectionMatrix;
	float m_AspectRatio;
	float m_FOV;
	float m_NearPlane;
	float m_FarPlane;

	const Shader& m_Shader;
};