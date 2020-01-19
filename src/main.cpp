#include "chromaray.h"
#include "Window.h"

#include "gfx/Shader.h"
#include "gfx/VertexBuffer.h"
#include "gfx/IndexBuffer.h"
#include "gfx/VertexArray.h"

#include "FileLoader.h"

int main() {
	Window window(G_WINDOW_WIDTH, G_WINDOW_HEIGHT, G_WINDOW_TITLE);

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

	VertexBuffer vBuffer(positions, sizeof(positions));
	IndexBuffer iBuffer(indices, 6);
	VertexArray vArray(3, GL_FLOAT, 0);

	Shader shader(readFile("res/glsl/basic.vert"), readFile("res/glsl/basic.frag"));
	shader.use();

	while (!window.shouldClose()) {
		window.clear();

		glDrawElements(GL_TRIANGLES, iBuffer.m_Length, GL_UNSIGNED_INT, nullptr);

		window.update();
	}

	return 0;
}