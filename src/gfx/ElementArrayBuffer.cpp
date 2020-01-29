#include "ElementArrayBuffer.hpp"

ElementArrayBuffer::ElementArrayBuffer(const unsigned int* data, unsigned int length) {
	glGenBuffers(1, &m_ID);
	bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(unsigned int), data, GL_STATIC_DRAW);
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