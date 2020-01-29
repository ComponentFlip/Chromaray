#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include "chromaray.hpp"
#include "../libs/stb_image.h"
#include "gfx/Texture.hpp"

struct LoadedImage {
	unsigned char* pixels;
	unsigned int width, height;
};

std::string readFile(std::string path);