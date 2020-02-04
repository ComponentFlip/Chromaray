#pragma once

#include <GL/glew.h>

class ArrayBuffer {
public:
	ArrayBuffer(const void* data, unsigned dataSize, bool dynamic);
	~ArrayBuffer();

	void bufferData(const void* data, unsigned dataSize);

	void bind();
	void unbind();
private:
	unsigned m_ID;
	bool m_Dynamic;
};