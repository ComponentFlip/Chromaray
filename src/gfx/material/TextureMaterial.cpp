#include "TextureMaterial.hpp"

TextureMaterial::TextureMaterial(std::vector<int> texCoords, Texture& texture) 
	: Material("texture")
	, m_TexCoordBuffer(texCoords.data(), texCoords.size() * sizeof(int)) 
	, m_Texture(texture)
{
	glEnableVertexAttribArray(m_TexCoordPointer);
	glVertexAttribPointer(m_TexCoordPointer, 2, GL_UNSIGNED_INT, GL_FALSE, 0, nullptr);

	m_Shader.bindAttribute(m_TexCoordPointer, "texCoords");
}

void TextureMaterial::prepare() const {
	m_Shader.use();
	m_Texture.bind();
}