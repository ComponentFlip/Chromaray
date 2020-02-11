#include "Model.hpp"

#include <GL/glew.h>

void ChGraphics::storeModel(ChGraphics::Model* model) {
	// TODO: Check that the vertex data is compatible

	glGenVertexArrays(1, &model->vArrayID);
	glBindVertexArray(model->vArrayID);

	glGenBuffers(1, &model->vBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, model->vBufferID);
	glBufferData(GL_ARRAY_BUFFER, model->vertices.size() * sizeof(float), model->vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &model->iBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->iBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model->indices.size() * sizeof(unsigned), model->indices.data(), GL_STATIC_DRAW);

	/*
	* VERTEX ATTRIBUTES
	* 0: Positions
	* 1: Colour
	* 2: Texture Coordinates 
	*/
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glVertexAttribPointer(0, 3, GL_FLOAT, false, 8 * sizeof(float), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 8 * sizeof(float), (const void*)12);
	glVertexAttribPointer(2, 2, GL_FLOAT, false, 8 * sizeof(float), (const void*)8);
}

void ChGraphics::deleteModel(ChGraphics::Model* model) {
	glDeleteBuffers(1, &model->vBufferID);
	glDeleteBuffers(1, &model->iBufferID);
	glDeleteVertexArrays(1, &model->vArrayID);
}