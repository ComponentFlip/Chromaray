#include "TextureAtlas.hpp"

TextureAtlas::TextureAtlas(Image& image, int tileSize) : m_Texture(image), m_TileSize(tileSize) {}

std::vector<float> TextureAtlas::getTexCoords(std::vector<float> original, int xOffset, int yOffset) {
	std::vector<float> newCoords;

	int xTiles = m_Texture.getWidth() / m_TileSize;
	int yTiles = m_Texture.getHeight() / m_TileSize;

	// Flip y-offset
	yOffset = -(yOffset + 1);

	// Loop through every other point
	for (unsigned i = 0; i < original.size() / 2; i++) {
		// Get the x and y from the current position
		float x = original[i * 2 + 0];
		float y = original[i * 2 + 1];

		newCoords.push_back((x + xOffset) / xTiles);
		newCoords.push_back((y + yOffset) / yTiles);
	}

	return newCoords;
}