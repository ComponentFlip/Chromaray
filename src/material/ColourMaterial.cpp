#include "ColourMaterial.hpp"

ColourMaterial::ColourMaterial(int inputColour) : Material("colour") {
	FloatColour colour = RGBtoFloats(inputColour);

	m_Shader.use();
	glUniform4f(m_Shader.getUniformLocation("colour"), colour.r, colour.g, colour.b, colour.a);
	m_Shader.stop();

	bindAllAttribs();
}

void ColourMaterial::bindAllAttribs() {
	m_Shader.bindAttribute(Constants::VERTEXARRAY_POSITION_POINTER, "position");
}