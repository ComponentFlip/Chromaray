#include "ColourMaterial.hpp"

ColourMaterial::ColourMaterial(int colour) : Material("colour") {
	glEnableVertexAttribArray(Constants::VERTEXARRAY_POSITION_POINTER);
	glVertexAttribPointer(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	// Get the ARGB colour channels out from the colour integer
	int a = colour >> 24 & 0xff;
	int r = colour >> 16 & 0xff;
	int g = colour >> 8 & 0xff;
	int b = colour & 0xff;

	m_Shader.use();

	glUniform4f(m_Shader.getUniformLocation("colour"), r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);

	m_Shader.stop();

	bindAllAttribs();
}

void ColourMaterial::bindAllAttribs() {
	m_Shader.bindAttribute(Constants::VERTEXARRAY_POSITION_POINTER, "position");
}