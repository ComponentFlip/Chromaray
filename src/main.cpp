#include <vector>

#include "chromaray.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"

#include "material/TextureMaterial.hpp"

#include "Window.hpp"
#include "FileLoader.hpp"

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE);
	window.setGLVersion(3, 2);
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

	Model model(positions, indices);
	TextureMaterial material(texCoords);
	material.useShader();

	LoadedImage image = loadTexture("res/tex/test.png");
	Texture texture(image.pixels, image.width, image.height);
	texture.bind();

	// Enable alpha blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	while (!window.shouldClose()) {
		window.clear(0xff4499bb);

		model.draw();

		window.update();
	}

	return 0;
}