#pragma once

#include <vector>

namespace ChGraphics {
	struct Model {
		std::vector<float> vertices;
		std::vector<unsigned> indices;

		unsigned vBufferID, iBufferID, vArrayID;
	};

	// Store model data into OpenGL, will modify IDs.
	void storeModel(Model* model);

	// Delete any stored model data.
	void deleteModel(Model* model);
}