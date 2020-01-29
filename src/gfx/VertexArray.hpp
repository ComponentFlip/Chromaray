#pragma once

#include <GL/glew.h>

class VertexArray {
public:
	VertexArray(unsigned index, unsigned elements, unsigned type);
	~VertexArray();

	void bind();
	void unbind();
private:
	unsigned m_ID;
	unsigned m_Index;
};