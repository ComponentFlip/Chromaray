#include "Renderer.hpp"

Renderer::Renderer(Scene* scene) : m_Scene(scene) {
	// Enable alpha blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::render(Model& model, Material& material) {
	model.bindAll();
	material.prepare();
	
	material.bindAttribute(model.m_AttributePosition, "a_pos");

	material.bindUniform(getTransformationMatrix(model.m_Transformation), "u_tMatrix");
	material.bindUniform(getViewMatrix(m_Scene->m_Camera), "u_vMatrix");
	material.bindUniform(m_Scene->getProjectionMatrix(), "u_pMatrix");

	GLCALL(glDrawElements(GL_TRIANGLES, model.m_VertexCount, GL_UNSIGNED_INT, nullptr));
}