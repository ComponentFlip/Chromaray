#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "util/conversions.hpp"

class Scene {
public:
	Scene(const int width, const int height);

	void update(const int width, const int height);

	glm::mat4 getProjectionMatrix() const;

	Transformation m_Camera;
private:
	float m_AspectRatio;
	float m_FOV;
	float m_NearPlane;
	float m_FarPlane;

	glm::mat4 m_ProjectionMatrix;
};