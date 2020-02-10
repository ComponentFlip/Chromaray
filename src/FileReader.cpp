#include "FileReader.hpp"

#include <sstream>
#include <fstream>

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