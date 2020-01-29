#pragma once

#include <GL/glew.h>

class ElementArrayBuffer {
public:
	ElementArrayBuffer(const unsigned* data, unsigned length);
	~ElementArrayBuffer();

	void bind();
	void unbind();
private:
	unsigned m_ID;
};