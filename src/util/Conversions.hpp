#pragma once

#include <glm/glm.hpp>

namespace ChUtil {
	struct Transform {
		Transform() 
			: position(glm::vec3(0, 0, 0))
			, rotation(glm::vec3(0, 0, 0))
			, scale(glm::vec3(1, 1, 1)) {}

		glm::vec3 position, rotation, scale;
	};

	glm::mat4 createTransformMatrix(const Transform& transform);
	glm::mat4 createViewMatrix(const Transform& camera);
}