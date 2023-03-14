#pragma once

#include "entities/camera.h"

namespace Punji::Graphics {
	class Renderer {
	public:
		Renderer();
		~Renderer();

		void SetCamera(Camera* camera);
		Camera* getCamera() { return _camera; }
	private:
		Camera* _camera;
	};
}