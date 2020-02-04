#pragma once

#include <vector>

#include "../../chromaray.hpp"
#include "../gl/ArrayBuffer.hpp"
#include "../gl/Texture.hpp"

#include "Material.hpp"

class TextureMaterial : public Material {
public:
	TextureMaterial(std::vector<float> texCoords, Texture& texture);

	void setData(std::vector<float> texCoords);

	void prepare() const override;
private:
	const int m_TexCoordPointer;
	ArrayBuffer m_TexCoordBuffer;
	Texture& m_Texture;
};