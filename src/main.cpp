#include <vector>

#include "chromaray.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"

#include "material/TextureMaterial.hpp"

#include "Window.hpp"
#include "FileLoader.hpp"

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE.c_str());

	std::vector<float> positions = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	std::vector<int> texCoords = {
		0, 0,
		1, 0,
		1, 1,
		0, 1
	};

	Model model(positions, indices);
	TextureMaterial material(texCoords);
	material.useShader();

	unsigned int texture = loadTexture("res/tex/test.png");
	glBindTexture(GL_TEXTURE_2D, texture);

	while (!window.shouldClose()) {
		window.clear(0xffff00ff);

		glDrawElements(GL_TRIANGLES, model.m_VertexCount, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	glDeleteTextures(1, &texture);

	return 0;
}