#pragma once

namespace Punji::Graphics {
	class Renderer {
	public:
		Renderer();
		
		void SetPixel();

		~Renderer();

		//void SetCamera(Camera* camera);
		//Camera* getCamera() { return _camera; }
	private:
		//Camera* _camera;

		void ResizeBuffer() {}
	};
}