#pragma once

#include <vector>

#include "Image.hpp"

class TextureAtlas {
public:
	TextureAtlas(Image& image, int tileSize);

	std::vector<float> getTexCoords(const std::vector<float> original, int xOffset, int yOffset);
private:
	Image& m_Texture;
	int m_TileSize;
};