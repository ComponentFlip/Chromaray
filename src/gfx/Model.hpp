#pragma once

#include <vector>

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
private:
	ArrayBuffer m_VertexBuffer;
	ElementArrayBuffer m_IndexBuffer;
	VertexArray m_VertexArray;
};