#pragma once

#include <string>

namespace ChIO {
	class Image {
	public:
		Image(const char* path);
		~Image();

		int getWidth() { return m_Width; }
		int getHeight() { return m_Height; }
		unsigned char* getPixels() { return m_Pixels; }

	private:
		int m_Width, m_Height, m_BitDepth;
		unsigned char* m_Pixels;
	};

	std::string readTextFile(const char* filename);
}