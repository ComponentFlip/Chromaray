#pragma once

#include <GL/glew.h>

class VertexArray {
public:
	VertexArray(unsigned index, unsigned elements, unsigned type);
	~VertexArray();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
	unsigned int m_Index;
};