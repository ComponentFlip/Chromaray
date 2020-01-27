#pragma once

#include <GL/glew.h>

class VertexArray {
public:
	VertexArray(unsigned int index, unsigned int elements, unsigned int type);
	~VertexArray();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
	unsigned int m_Index;
};