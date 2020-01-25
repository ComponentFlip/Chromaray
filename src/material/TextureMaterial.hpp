#pragma once

#include <vector>

#include "../chromaray.hpp"

#include "Material.hpp"

class TextureMaterial : public Material {
public:
	TextureMaterial(std::vector<int> texCoords);
	~TextureMaterial();

private:
	const int m_TexCoordPointer = 1;
	unsigned int m_TexCoordBuffer;

protected:
	void bindAllAttribs() override;
};