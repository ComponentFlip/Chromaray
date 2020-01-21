#include "chromaray.h"

#include "gfx/Shader.h"
#include "gfx/Model.h"

#include "Window.h"
#include "FileLoader.h"

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE.c_str());

	float positions[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	Model model(positions, indices, sizeof(positions), sizeof(indices));

	Shader shader(readFile(Constants::SHADER_PATH + "basic.vert"), readFile(Constants::SHADER_PATH + "basic.frag"));
	shader.use();

	while (!window.shouldClose()) {
		window.clear();

		glDrawElements(GL_TRIANGLES, model.m_VertexCount, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	return 0;
}