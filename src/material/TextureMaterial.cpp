#include "TextureMaterial.hpp"

TextureMaterial::TextureMaterial(std::vector<int> texCoords) : Material("texture") {
	glEnableVertexAttribArray(Constants::VERTEXARRAY_POSITION_POINTER);
	glVertexAttribPointer(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	int* texCoordData = &texCoords[0];

	glGenBuffers(1, &m_TexCoordBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordBuffer);
	glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(int), texCoordData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(m_TexCoordPointer);
	glVertexAttribPointer(m_TexCoordPointer, 2, GL_UNSIGNED_INT, GL_FALSE, 0, nullptr);

	bindAllAttribs();
}

TextureMaterial::~TextureMaterial() {
	glDeleteBuffers(1, &m_TexCoordBuffer);
}

void TextureMaterial::bindAllAttribs() {
	m_Shader.bindAttribute(Constants::VERTEXARRAY_POSITION_POINTER, "position");
	m_Shader.bindAttribute(m_TexCoordPointer, "texCoords");
}