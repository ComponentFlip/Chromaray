#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include <GL/glew.h>

#include "chromaray.hpp"
#include "../libs/stb_image.h"

std::string readFile(std::string path);
unsigned int loadTexture(std::string path);