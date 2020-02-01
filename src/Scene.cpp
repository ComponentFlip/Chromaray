#include "Scene.hpp"

Scene::Scene(const int width, const int height) 
	: m_AspectRatio((width * 1.0f) / (height * 1.0f)) 
	, m_FOV(Constants::SCENE_FOV)
	, m_NearPlane(Constants::SCENE_NEARPLANE)
	, m_FarPlane(Constants::SCENE_FARPLANE)
{
	m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane);
}

void Scene::update(const int width, const int height) {
	m_AspectRatio = (width * 1.0f) / (height * 1.0f);
	m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane);
}

glm::mat4 Scene::getProjectionMatrix() const {
	return m_ProjectionMatrix;
}