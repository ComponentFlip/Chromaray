#pragma once

#include <GL/glew.h>

// Forward declaration
class Image;

class Texture {
public:
	Texture(const Image& image);
	~Texture();

	void bind() const;
	void unbind() const;
private:
	unsigned m_ID;
};