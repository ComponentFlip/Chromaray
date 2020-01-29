#pragma once

#include <GL/glew.h>

class ArrayBuffer {
public:
	ArrayBuffer(const void* data, unsigned dataSize);
	~ArrayBuffer();

	void bind();
	void unbind();
private:
	unsigned m_ID;
};