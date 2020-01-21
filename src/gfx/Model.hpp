#pragma once

#include <GLEW/glew.h>

class Model {
public:
	Model(const float* vertices, const unsigned int* indices, unsigned int verticesSize, unsigned int indicesSize);
	~Model();

	const unsigned int m_VertexCount;
private:
	unsigned int m_VertexBuffer;
	unsigned int m_IndexBuffer;
	unsigned int m_VertexArray;
};