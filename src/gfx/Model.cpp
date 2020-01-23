#include "Model.hpp"

Model::Model(std::vector<float> vertices, std::vector<unsigned int> indices) : m_VertexCount(indices.size()) {
	float* vertexData = &vertices[0];
	unsigned int* indexData = &indices[0];

	glGenBuffers(1, &m_VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &m_IndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned int), indexData, GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_VertexArray);
	glBindVertexArray(0);
}

Model::~Model() {
	glDeleteBuffers(1, &m_VertexBuffer);
	glDeleteBuffers(1, &m_IndexBuffer);
	glDeleteVertexArrays(1, &m_VertexArray);
}
