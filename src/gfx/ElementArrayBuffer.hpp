#pragma once

#include <GL/glew.h>

class ElementArrayBuffer {
public:
	ElementArrayBuffer(const unsigned* data, unsigned length);
	~ElementArrayBuffer();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};