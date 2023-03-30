#pragma ACME path ./engine/entities
#pragma once

#include <glm/glm.hpp>

#include "entity.h"

namespace Punji::Engine {
	class Camera : public Punji::Engine::Entity {
	public:
		Camera() {}

		void Init() {}
		void Update() {}
		void Render() {}
		//void Destroy() {}

		~Camera() {}

		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
		glm::mat4 projection;
	};
}