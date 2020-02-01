#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "../chromaray.hpp"

#include "gl/ArrayBuffer.hpp"
#include "gl/ElementArrayBuffer.hpp"
#include "gl/VertexArray.hpp"

class Model {
public:
	Model(std::vector<float> vertices, std::vector<unsigned> indices);

	void bindAll();
	void unbindAll();

	const unsigned m_VertexCount;
	const unsigned m_AttributePosition;
	
	Transformation m_Transformation;
private:
	ArrayBuffer m_VertexBuffer;
	ElementArrayBuffer m_IndexBuffer;
	VertexArray m_VertexArray;
};