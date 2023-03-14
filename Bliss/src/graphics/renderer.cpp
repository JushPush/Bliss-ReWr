#include <graphics/renderer.h>

namespace Punji {
	Renderer::Renderer() {

	}

	Renderer::~Renderer() {

	}

	void Renderer::SetCamera(Camera* camera) {
		this->_camera = camera;
	}
}