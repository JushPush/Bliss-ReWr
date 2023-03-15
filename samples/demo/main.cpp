#include <Bliss.h>

#include <math.h>

using namespace Punji;
using namespace Punji::Graphics;

int main(int argc, char* argv[]) {
	//Punji::Graphics::Window window = Punji::Graphics::Window(0, 0, 800, 600, "Bliss Demo", false); //Punji::CreateWindow(0, 0, 800, 600, "Bliss Demo", false);
	Window mainWindow = Window(0,0,800,600,"AHH",false);

	while (!glfwWindowShouldClose(mainWindow.getWindow()))
	{
		mainWindow.ClearBuffer();
		glfwPollEvents();
	}

	mainWindow.Destroy();

	//Punji::DestroyWindow(window);

	return 1;
}