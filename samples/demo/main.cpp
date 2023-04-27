//#include <Bliss.h>
#include <bliss_core.hpp>
#include <bliss_graphics.hpp>

using namespace pji::Core;
using namespace pji::Graphics;

int main(int argc, char* argv[]) {
	Window mainWindow = Window(0,0,800,600,"Bliss Demo",false);

	mainWindow.Init();
	
	Camera camera = Camera();

	Entity* etst = new Entity();

	etst->addComponent<TransformComponent>();

	etst->addComponent<TextureComponent>((std::string)"./res/bricks.jpg");
	etst->addComponent<ShaderComponent>((std::string)"./res/basicShader");
	etst->addComponent<MeshComponent>((std::string)"./res/teapot.obj");

	etst->getComponent<TransformComponent>()->pos.z -= 1;

	while (!mainWindow.ShouldClose()) {
		mainWindow.SwapBuffers();
		glfwPollEvents();

		etst->getComponent<TextureComponent>()->Bind();
		etst->getComponent<ShaderComponent>()->Bind();
		etst->getComponent<ShaderComponent>()->Update(camera);
		etst->getComponent<MeshComponent>()->Render();
	}

	etst->getComponent<TextureComponent>()->Unload();

	mainWindow.Destroy();

	return 1;
}