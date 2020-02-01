#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include "chromaray.hpp"
#include "../libs/stb_image.h"

struct LoadedImage {
	unsigned char* pixels;
	unsigned width, height;
};

std::string readFile(std::string path);