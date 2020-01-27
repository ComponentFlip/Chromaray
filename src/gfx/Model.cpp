#include "Model.hpp"

Model::Model(std::vector<float> vertices, std::vector<unsigned int> indices)
	: m_VertexCount(indices.size()), 
	m_VertexBuffer(vertices.data(), vertices.size() * sizeof(float)), 
	m_IndexBuffer(indices.data(), indices.size()),
	m_VertexArray(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT)
{
	m_VertexBuffer.bind();
	m_IndexBuffer.bind();
	m_VertexArray.bind();
}