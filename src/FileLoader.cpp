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
