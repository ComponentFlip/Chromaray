#include "Texture.hpp"

#include "Image.hpp"

Texture::Texture(const Image& image) {
	glGenTextures(1, &m_ID);
	bind();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getWidth(), image.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixels());

	// Set image scaling to nearest neighbour to keep the pixels sharp
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP);

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