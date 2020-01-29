#include "ElementArrayBuffer.hpp"

ElementArrayBuffer::ElementArrayBuffer(const unsigned* data, unsigned length) {
	glGenBuffers(1, &m_ID);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(unsigned), data, GL_STATIC_DRAW);
}

ElementArrayBuffer::~ElementArrayBuffer() {
	glDeleteBuffers(1, &m_ID);
}

void ElementArrayBuffer::bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void ElementArrayBuffer::unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}