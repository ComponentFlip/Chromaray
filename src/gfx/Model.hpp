#pragma once

#include <vector>

#include "../chromaray.hpp"

#include "ArrayBuffer.hpp"
#include "ElementArrayBuffer.hpp"
#include "VertexArray.hpp"

class Model {
public:
	Model(std::vector<float> vertices, std::vector<unsigned int> indices);

	const unsigned int m_VertexCount;
private:
	ArrayBuffer m_VertexBuffer;
	ElementArrayBuffer m_IndexBuffer;
	VertexArray m_VertexArray;
};