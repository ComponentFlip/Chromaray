#include <vector>

#include "chromaray.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"

#include "material/TextureMaterial.hpp"

#include "Window.hpp"
#include "FileLoader.hpp"

#define GLCALL(x) x; get_gl_errors(__LINE__);

void get_gl_errors(int line) {
		GLenum error;
		while ((error = glGetError()) != GL_NO_ERROR) {
			std::cout << "OPENGL ERROR (&line " << std::dec << line << "): " << std::hex << error << std::endl;
		}
}

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE.c_str());
	window.set_gl_version(3, 2);
	window.open();

	std::cout << "Using GLFW " << glfwGetVersionString() << std::endl;
	std::cout << "Using OpenGL " << glGetString(GL_VERSION) << std::endl;

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

	// By default, the OpenGL CORE profile does not
	// construct a default Vertex Array. We have to
	// create our own here and bind it.
	unsigned int vao;
	GLCALL(glCreateVertexArrays(1, &vao));
	GLCALL(glBindVertexArray(vao));

	Model model(positions, indices);
	TextureMaterial material(texCoords);
	material.useShader();

	unsigned int texture = loadTexture("res/tex/test.png");
	glBindTexture(GL_TEXTURE_2D, texture);

	while (!window.shouldClose()) {
		window.clear(0xffff00ff);

		GLCALL(glBindVertexArray(vao));
		model.draw();

		window.update();
	}

	glDeleteTextures(1, &texture);

	return 0;
}