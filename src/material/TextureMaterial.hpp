#pragma once

#include <vector>

#include "../chromaray.hpp"
#include "../gfx/ArrayBuffer.hpp"

#include "Material.hpp"

class TextureMaterial : public Material {
public:
	TextureMaterial(std::vector<int> texCoords);

private:
	const int m_TexCoordPointer = 1;
	ArrayBuffer m_TexCoordBuffer;

protected:
	void bindAllAttribs() override;
};