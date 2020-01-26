#pragma once

#include <GL/glew.h>
#include <vector>

class Model {
public:
	Model(std::vector<float> vertices, std::vector<unsigned int> indices);
	~Model();

	const unsigned int m_VertexCount;
private:
	unsigned int m_VertexBuffer;
	unsigned int m_IndexBuffer;
	unsigned int m_VertexArray;
};