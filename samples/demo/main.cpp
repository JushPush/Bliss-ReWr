#include <Bliss.h>

#include <math.h>

#include <engine/entities/ecs/component_mesh.h>
#include <engine/entities/ecs/component_transform.h>
#include <engine/entities/ecs/component_shader.h>

using namespace Punji;
using namespace Punji::Graphics;
using namespace Punji::Engine;

int main(int argc, char* argv[]) {
	//Punji::Graphics::Window window = Punji::Graphics::Window(0, 0, 800, 600, "Bliss Demo", false); //Punji::CreateWindow(0, 0, 800, 600, "Bliss Demo", false);
	Window mainWindow = Window(0,0,800,600,"Bliss Demo",false);

	Camera camera = Camera();

	Entity* entityTST = new Entity();

	entityTST->addComponent<TransformComponent>();
	entityTST->addComponent<ShaderComponent>((std::string)"res/basicShader");
	entityTST->addComponent<MeshComponent>((std::string)"res/teapot.obj");

	while (!mainWindow.ShouldClose())
	{
		mainWindow.SwapBuffers();
		glfwPollEvents();

		entityTST->getComponent<ShaderComponent>()->Bind();
		entityTST->getComponent<ShaderComponent>()->Update(camera);
		entityTST->getComponent<MeshComponent>()->Render();
	}

	mainWindow.Destroy();

	return 1;
}