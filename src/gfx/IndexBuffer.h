#pragma once

#include <GLEW/glew.h>

class IndexBuffer {
public:
	const unsigned int m_Length;

	IndexBuffer(const unsigned int* data, unsigned int length);
	~IndexBuffer();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};