#include "Image.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

#include "../../libs/stb_image.h"

Image::Image(const std::string& path)
:
    m_Image(nullptr)
{
    loadImage(path);
}

Image::~Image() {
    stbi_image_free(m_Image);
}

void Image::loadImage(const std::string& path) {
    stbi_set_flip_vertically_on_load(true);
    m_Image = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BitDepth, STBI_rgb_alpha);
    if (!m_Image) {
        std::cerr << "ERROR: Image failed to load! [" << stbi_failure_reason() << "]" << std::endl;
    }
}