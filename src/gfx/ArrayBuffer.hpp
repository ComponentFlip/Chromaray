#pragma once

#include <GL/glew.h>

class ArrayBuffer {
public:
	ArrayBuffer(const void* data, unsigned int dataSize);
	~ArrayBuffer();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};