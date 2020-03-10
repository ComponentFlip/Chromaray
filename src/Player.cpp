#include "Player.hpp"

#include "Chromaray.hpp"
#include "Window.hpp"
#include <GLFW/glfw3.h>

void Player::update(ChUtil::Transform& camera) {
	if (ChCore::keyDown(GLFW_KEY_LEFT)) camera.rotate(0, -ChConstants::PLAYER_TURN_SPEED, 0);
	if (ChCore::keyDown(GLFW_KEY_RIGHT)) camera.rotate(0, ChConstants::PLAYER_TURN_SPEED, 0);

	if (ChCore::keyDown(GLFW_KEY_W)) {
		camera.position.x += sinf(glm::radians(camera.rotation.y)) * ChConstants::PLAYER_MOVE_SPEED;
		camera.position.z -= cosf(glm::radians(camera.rotation.y)) * ChConstants::PLAYER_MOVE_SPEED;
	}
	if (ChCore::keyDown(GLFW_KEY_S)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y)) * ChConstants::PLAYER_MOVE_SPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y)) * ChConstants::PLAYER_MOVE_SPEED;
	}
	if (ChCore::keyDown(GLFW_KEY_A)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y + 90)) * ChConstants::PLAYER_MOVE_SPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y + 90)) * ChConstants::PLAYER_MOVE_SPEED;
	}
	if (ChCore::keyDown(GLFW_KEY_D)) {
		camera.position.x -= sinf(glm::radians(camera.rotation.y - 90)) * ChConstants::PLAYER_MOVE_SPEED;
		camera.position.z += cosf(glm::radians(camera.rotation.y - 90)) * ChConstants::PLAYER_MOVE_SPEED;
	}
}