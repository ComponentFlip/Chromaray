#include "TextureMaterial.hpp"

TextureMaterial::TextureMaterial(std::vector<int> texCoords) : Material("texture"), m_TexCoordBuffer(texCoords.data(), texCoords.size() * sizeof(int)) {
//	glGenBuffers(1, &m_TexCoordBuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, m_TexCoordBuffer);
//	glBufferData(GL_ARRAY_BUFFER, texCoords.size() * sizeof(int), texCoords.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(m_TexCoordPointer);
	glVertexAttribPointer(m_TexCoordPointer, 2, GL_UNSIGNED_INT, GL_FALSE, 0, nullptr);

	bindAllAttribs();
}

void TextureMaterial::bindAllAttribs() {
	m_Shader.bindAttribute(Constants::VERTEXARRAY_POSITION_POINTER, "position");
	m_Shader.bindAttribute(m_TexCoordPointer, "texCoords");
}