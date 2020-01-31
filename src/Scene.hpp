#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "gfx/Shader.hpp"
#include "util/conversions.hpp"

class Scene {
public:
	Scene(const int width, const int height, const Shader& shader);

	void update(const int width, const int height);

	Transformation m_Camera;
private:
	float m_AspectRatio;
	float m_FOV;
	float m_NearPlane;
	float m_FarPlane;

	glm::mat4 m_ProjectionMatrix;
	const Shader& m_Shader;
};