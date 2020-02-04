#include "TextureMaterial.hpp"

TextureMaterial::TextureMaterial(std::vector<float> texCoords, Texture& texture)
	: Material("texture")
	, m_TexCoordBuffer(texCoords.data(), texCoords.size() * sizeof(int), true)
	, m_Texture(texture)
	, m_TexCoordPointer(1)
{
	glEnableVertexAttribArray(m_TexCoordPointer);
	glVertexAttribPointer(m_TexCoordPointer, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	m_Shader.bindAttribute(m_TexCoordPointer, "a_texCoords");
}

void TextureMaterial::setData(std::vector<float> texCoords) {
	m_TexCoordBuffer.bufferData(texCoords.data(), texCoords.size() * sizeof(int));
}

void TextureMaterial::prepare() const {
	m_Shader.use();
	m_Texture.bind();
}