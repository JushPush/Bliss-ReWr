#pragma once

#include <glm/glm.hpp>

namespace Punji {
	class Camera {
	public:
		Camera();
		~Camera();

		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
		glm::vec3 projection;
	};
}