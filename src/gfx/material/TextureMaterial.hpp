#pragma once

#include <vector>

#include "../../chromaray.hpp"
#include "../gl/ArrayBuffer.hpp"
#include "../gl/Texture.hpp"

#include "Material.hpp"

class TextureMaterial : public Material {
public:
	TextureMaterial(std::vector<int> texCoords, Texture& texture);

	void prepare() const override;
private:
	const int m_TexCoordPointer = 1;
	ArrayBuffer m_TexCoordBuffer;
	Texture& m_Texture;
};