#include "ColourMaterial.hpp"

ColourMaterial::ColourMaterial(int inputColour) : Material("colour") {
	glEnableVertexAttribArray(Constants::VERTEXARRAY_POSITION_POINTER);
	glVertexAttribPointer(Constants::VERTEXARRAY_POSITION_POINTER, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	FloatColour colour = RGBtoFloats(inputColour);

	m_Shader.use();

	glUniform4f(m_Shader.getUniformLocation("colour"), colour.r, colour.g, colour.b, colour.a);

	m_Shader.stop();

	bindAllAttribs();
}

void ColourMaterial::bindAllAttribs() {
	m_Shader.bindAttribute(Constants::VERTEXARRAY_POSITION_POINTER, "position");
}