#include "ArrayBuffer.hpp"

ArrayBuffer::ArrayBuffer(const void* data, unsigned int dataSize) {
	glGenBuffers(1, &m_ID);
	bind();
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

ArrayBuffer::~ArrayBuffer() {
	glDeleteBuffers(1, &m_ID);
}

void ArrayBuffer::bind() {
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void ArrayBuffer::unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}