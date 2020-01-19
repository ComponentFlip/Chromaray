#pragma once

#include <GLEW/glew.h>

class VertexArray {
public:
	VertexArray(unsigned int length, unsigned int type, unsigned int index);
	~VertexArray();

	void enable();
	void disable();
private:
	unsigned int m_ID;
	unsigned int m_Index;
};
