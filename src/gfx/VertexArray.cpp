#include "VertexArray.hpp"

VertexArray::VertexArray(unsigned index, unsigned elements, unsigned int type) : m_Index(index) {
	glGenVertexArrays(1, &m_ID);
	glBindVertexArray(m_ID);

	bind();
	glVertexAttribPointer(m_Index, elements, type, GL_FALSE, 0, nullptr);
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_ID);
}

void VertexArray::bind() {
	glEnableVertexAttribArray(m_Index);
}

void VertexArray::unbind() {
	glDisableVertexAttribArray(m_Index);
}