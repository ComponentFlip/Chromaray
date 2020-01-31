#include "Scene.hpp"

Scene::Scene(const int width, const int height, const Shader& shader) 
	: m_AspectRatio((width * 1.0f) / (height * 1.0f)) 
	, m_FOV(Constants::SCENE_FOV)
	, m_NearPlane(Constants::SCENE_NEARPLANE)
	, m_FarPlane(Constants::SCENE_FARPLANE) 
	, m_Shader(shader)
{
	m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane);
	m_Shader.setMatrixUniform(m_ProjectionMatrix, "u_pMatrix");
	m_Shader.setMatrixUniform(getTransformationMatrix(m_Camera), "u_vMatrix");
}

void Scene::update(const int width, const int height) {
	m_AspectRatio = (width * 1.0f) / (height * 1.0f);

	m_ProjectionMatrix = glm::perspective(glm::radians(m_FOV), m_AspectRatio, m_NearPlane, m_FarPlane);
	m_Shader.setMatrixUniform(m_ProjectionMatrix, "u_pMatrix");
	m_Shader.setMatrixUniform(getTransformationMatrix(m_Camera), "u_vMatrix");
}