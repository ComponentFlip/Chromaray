#include "VertexArray.h"

VertexArray::VertexArray(unsigned int length, unsigned int type, unsigned int index) : m_Index(index) {
	glGenVertexArrays(1, &m_ID);
	enable();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, length, type, GL_FALSE, 0, (void*)0);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::enable() {
	glBindVertexArray(m_Index);
}

void VertexArray::disable() {
	glBindVertexArray(0);
}