#pragma once

#include <glm/glm.hpp>

namespace ChUtil {
	struct Transform {
		Transform() 
			: position(glm::vec3(0, 0, 0))
			, rotation(glm::vec3(0, 0, 0))
			, scale(glm::vec3(1, 1, 1)) {}
		
		void setPosition(float x, float y, float z) { position = glm::vec3(x, y, z); }
		void setRotation(float x, float y, float z) { rotation = glm::vec3(x, y, z); }
		void setScale(float x, float y, float z)    { scale    = glm::vec3(x, y, z); }

		void move(float x, float y, float z)   { position = glm::vec3(position.x + x, position.y + y, position.z + z); }
		void rotate(float x, float y, float z) { rotation = glm::vec3(rotation.x + x, rotation.y + y, rotation.z + z); }
		void resize(float x, float y, float z) { scale    = glm::vec3(scale.x + x, scale.y + y, scale.z + z); }
		
		glm::vec3 position, rotation, scale;
	};

	glm::mat4 createTransformMatrix(const Transform& transform);
	glm::mat4 createViewMatrix(const Transform& camera);
}