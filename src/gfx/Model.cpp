#include "Model.hpp"

#include "../chromaray.hpp"

Model::Model(std::vector<float> vertices, std::vector<unsigned> indices)
	: m_VertexCount(indices.size()), 
	m_VertexBuffer(vertices.data(), vertices.size() * sizeof(float)), 
	m_IndexBuffer(indices.data(), indices.size()),
	m_VertexArray(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT)
{
	bind();
}

void Model::draw() {
	bind();
	GLCALL(glDrawElements(GL_TRIANGLES, m_VertexCount, GL_UNSIGNED_INT, nullptr));
	unbind();
}

void Model::bind() {
	m_VertexBuffer.bind();
	m_IndexBuffer.bind();
	m_VertexArray.bind();
}

void Model::unbind() {
	m_VertexBuffer.unbind();
	m_IndexBuffer.unbind();
	m_VertexArray.unbind();
}