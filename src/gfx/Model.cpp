#include "Model.hpp"

Model::Model(std::vector<float> vertices, std::vector<unsigned int> indices) : m_VertexCount(indices.size()) {
	float* vertexData = &vertices[0];
	unsigned int* indexData = &indices[0];

	glGenBuffers(1, &m_VertexBuffer);
	glGenBuffers(1, &m_IndexBuffer);

	bind();

	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), vertexData, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned int), indexData, GL_STATIC_DRAW);
}

Model::~Model() {
	glDeleteBuffers(1, &m_VertexBuffer);
	glDeleteBuffers(1, &m_IndexBuffer);
}

void Model::draw() {
	bind();
	glDrawElements(GL_TRIANGLES, m_VertexCount, GL_UNSIGNED_INT, nullptr);
}

void Model::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
}