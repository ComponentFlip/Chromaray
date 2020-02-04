#include "ArrayBuffer.hpp"

ArrayBuffer::ArrayBuffer(const void* data, unsigned dataSize, bool dynamic) : m_Dynamic(dynamic) {
	glGenBuffers(1, &m_ID);
	bind();
	bufferData(data, dataSize);
}

void ArrayBuffer::bufferData(const void* data, unsigned dataSize) {
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, m_Dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
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