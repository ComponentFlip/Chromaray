#include "Texture.hpp"

Texture::Texture(const unsigned char* pixels, unsigned int width, unsigned int height) {
	glGenTextures(1, &m_ID);
	bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	// Set image scaling to nearest neighbour to keep the pixels sharp
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	unbind();
}

Texture::~Texture() {
	glDeleteTextures(1, &m_ID);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_ID);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}