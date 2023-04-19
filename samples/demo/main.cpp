//#include <Bliss.h>
#include <bliss_core.hpp>

/*using namespace Punji;
using namespace Punji::Graphics;
using namespace Punji::Engine;*/

int main(int argc, char* argv[]) {
	//Punji::Graphics::Window window = Punji::Graphics::Window(0, 0, 800, 600, "Bliss Demo", false); //Punji::CreateWindow(0, 0, 800, 600, "Bliss Demo", false);
	/*Window mainWindow = Window(0,0,800,600,"Bliss Demo",false);

	Camera camera = Camera();

	Entity* entityTST = new Entity();

	entityTST->addComponent<TransformComponent>();

	entityTST->getComponent<TransformComponent>()->pos.z -= 1;

	entityTST->addComponent<TextureComponent>((std::string)"./res/bricks.jpg");
	entityTST->addComponent<ShaderComponent>((std::string)"./res/basicShader");
	entityTST->addComponent<MeshComponent>((std::string)"./res/teapot.obj");

	while (!mainWindow.ShouldClose())
	{
		mainWindow.SwapBuffers();
		glfwPollEvents();

		entityTST->getComponent<TextureComponent>()->Bind();
		entityTST->getComponent<ShaderComponent>()->Bind();
		entityTST->getComponent<ShaderComponent>()->Update(camera);
		entityTST->getComponent<MeshComponent>()->Render();
	}

	entityTST->getComponent<TextureComponent>()->Unload();

	mainWindow.Destroy();*/

	return 1;
}