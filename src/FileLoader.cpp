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

LoadedImage loadTexture(std::string path) {
	LoadedImage image;
	int width, height, bitDepth;

	stbi_set_flip_vertically_on_load(true);
	unsigned char* pixels = stbi_load(path.c_str(), &width, &height, &bitDepth, STBI_rgb_alpha);

	image.pixels = pixels;
	image.width = width;
	image.height = height;

	// TODO: copy the data into the struct and call stbi_free_image
	// I could have the texture object created here but I wanted to create the texture object outside of the image loader

	return image;
}