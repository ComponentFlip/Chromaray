#include "FileReader.hpp"

#include <sstream>
#include <fstream>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "../libs/stb_image.h"

ChIO::Image::Image(const char* path) {
	stbi_set_flip_vertically_on_load(true);

	m_Pixels = stbi_load(path, &m_Width, &m_Height, &m_BitDepth, STBI_rgb_alpha);
	if (!m_Pixels) {
		std::cerr << "Failed to load image! Reason: " << stbi_failure_reason() << std::endl;
	}
}

ChIO::Image::~Image() {
	stbi_image_free(m_Pixels);
}

std::string ChIO::readTextFile(const char* path) {
	std::string result;
	std::ifstream stream(path);

	if (stream.is_open()) {
		std::stringstream sStream;
		sStream << stream.rdbuf();
		result = sStream.str();
	}

	stream.close();
	return result;
}