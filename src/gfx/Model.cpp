#include "Model.hpp"

#include "../chromaray.hpp"

Model::Model(std::vector<float> vertices, std::vector<unsigned> indices)
	: m_VertexCount(indices.size())
	, m_VertexBuffer(vertices.data(), vertices.size() * sizeof(float), false)
	, m_IndexBuffer(indices.data(), indices.size())
	, m_VertexArray(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT)
	, m_AttributePosition(0)
{}


void Model::bindAll() {
	m_VertexBuffer.bind();
	m_IndexBuffer.bind();
	m_VertexArray.bind();
}

void Model::unbindAll() {
	m_VertexBuffer.unbind();
	m_IndexBuffer.unbind();
	m_VertexArray.unbind();
}
