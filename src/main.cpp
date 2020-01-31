#include <vector>

#include "chromaray.hpp"

#include "gfx/Shader.hpp"
#include "gfx/Model.hpp"
#include "gfx/Image.hpp"
#include "Scene.hpp"

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
		-0.5f, -0.5f, -2.0f,
		 0.5f, -0.5f, -2.0f,
		 0.5f,  0.5f, -2.0f,
		-0.5f,  0.5f, -2.0f
	};

	std::vector<unsigned> indices = {
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
	material.m_Shader.use();

	Scene scene(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, material.m_Shader);

	Image image = Image("res/tex/test.png");
	Texture texture(image);
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