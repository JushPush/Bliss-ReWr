#include <graphics/renderer.h>

namespace Punji::Graphics {
	Renderer::Renderer() {

	}

	Renderer::~Renderer() {

	}

	void Renderer::SetCamera(Camera* camera) {
		this->_camera = camera;
	}
}