#include <vector>

#include "chromaray.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"

#include "material/ColourMaterial.hpp"

#include "Window.hpp"
#include "FileLoader.hpp"

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE.c_str());

	std::vector<float> positions = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
	};

	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	Model model(positions, indices);
	ColourMaterial material(0xff577f8e);
	material.useShader();

	while (!window.shouldClose()) {
		window.clear();

		glDrawElements(GL_TRIANGLES, model.m_VertexCount, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	return 0;
}