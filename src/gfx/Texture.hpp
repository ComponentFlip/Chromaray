#pragma once

#include <GL/glew.h>

class Texture {
public:
	Texture(const unsigned char* pixels, unsigned int width, unsigned int height);
	~Texture();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};