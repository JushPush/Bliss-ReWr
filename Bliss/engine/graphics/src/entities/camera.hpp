#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <bliss_core.hpp>

namespace Punji::Graphics {
    class Camera : public Punji::Core::Entity {
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

#endif