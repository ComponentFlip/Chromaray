#pragma once

#include <GL/glew.h>

// Forward declaration
class Image;

class Texture {
public:
	Texture(const Image& image);
	~Texture();

	void bind();
	void unbind();
private:
	unsigned int m_ID;
};