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

void updatePosition(Window& window, Transformation& camera) {
	if (window.isDown(GLFW_KEY_LEFT)) camera.rotate(0, -Constants::PLAYER_TURNSPEED, 0);
	if (window.isDown(GLFW_KEY_RIGHT)) camera.rotate(0, Constants::PLAYER_TURNSPEED, 0);

	if (window.isDown(GLFW_KEY_W)) {
		camera.position.x += sinf(glm::radians(camera.rotation.y)) * Constants::PLAYER_MOVESPEED;
		camera.position.z -= cosf(glm::radians(camera.rotation.y)) * Constants::PLAYER_MOVESPEED;
	}
	if (window.isDown(GLFW_KEY_S)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y)) * Constants::PLAYER_MOVESPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y)) * Constants::PLAYER_MOVESPEED;
	}
	if (window.isDown(GLFW_KEY_A)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y + 90)) * Constants::PLAYER_MOVESPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y + 90)) * Constants::PLAYER_MOVESPEED;
	}
	if (window.isDown(GLFW_KEY_D)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y - 90)) * Constants::PLAYER_MOVESPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y - 90)) * Constants::PLAYER_MOVESPEED;
	}
}

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

	model.m_Transformation.setPosition(0, 0, -1.5f);

	Clock clock;
	while (!window.shouldClose()) {
		float t = clock.getElapsed();

		updatePosition(window, scene.m_Camera);

		window.clear(0xff4499bb);

		scene.update(window.getWidth(), window.getHeight());
		renderer.render(model, material);

		window.update();
	}

	return 0;
}