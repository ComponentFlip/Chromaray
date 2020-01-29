#pragma once

#include <GL/glew.h>

class ElementArrayBuffer {
public:
	ElementArrayBuffer(const unsigned int* data, unsigned int length);
	~ElementArrayBuffer();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};