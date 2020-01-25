#include "FileLoader.hpp"

std::string readFile(std::string path) {
	std::string result;
	std::ifstream stream(path);

	if (stream.is_open()) {
		std::stringstream stringStream;
		stringStream << stream.rdbuf();
		result = stringStream.str();
		stream.close();
	}

	return result;
}

unsigned int loadTexture(std::string path) {
	unsigned int textureID;

	stbi_set_flip_vertically_on_load(true);

	int width, height, bitDepth;
	unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &bitDepth, STBI_rgb_alpha);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(pixels);

	return textureID;
}