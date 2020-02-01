#include <vector>
#include <chrono>

#include "chromaray.hpp"

#include "util/Clock.hpp"

#include "gfx/Model.hpp"
#include "gfx/Image.hpp"
#include "gfx/Renderer.hpp"
#include "gfx/gl/Texture.hpp"
#include "Scene.hpp"

#include "gfx/material/TextureMaterial.hpp"

#include "Window.hpp"
#include "FileLoader.hpp"

int main() {
	Window window(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT, Constants::WINDOW_TITLE);
	window.setGLVersion(3, 2);
	window.open();

	std::vector<float> positions = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
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

	Image image = Image("res/tex/test.png");
	Texture texture(image);

	Model model(positions, indices);
	TextureMaterial material(texCoords, texture);

	Scene scene(window.getWidth(), window.getHeight());

	Renderer renderer(&scene);
	
	Clock clock;
	while (!window.shouldClose()) {
		float t = clock.getElapsed();

		scene.m_Camera.setPosition(0, 0, sinf(t * 2.f) - 2.f);
		model.m_Transformation.setRotation(0, t * 128.f, 0);

		window.clear(0xff4499bb);

		scene.update(window.getWidth(), window.getHeight());
		renderer.render(model, material);

		window.update();
	}

	return 0;
}