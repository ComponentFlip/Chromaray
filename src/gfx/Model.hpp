#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "../chromaray.hpp"

#include "ArrayBuffer.hpp"
#include "ElementArrayBuffer.hpp"
#include "VertexArray.hpp"

class Model {
public:
	Model(std::vector<float> vertices, std::vector<unsigned> indices);

	void bind();
	void unbind();
	void draw();

	const unsigned m_VertexCount;
	
	Transformation m_Transformation;
private:
	ArrayBuffer m_VertexBuffer;
	ElementArrayBuffer m_IndexBuffer;
	VertexArray m_VertexArray;
};