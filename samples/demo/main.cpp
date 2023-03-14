#include <Bliss.h>

// ImGui integration
#include <common/imgui/imgui.h>
#include <math.h>

using namespace Punji;
using namespace Punji::Graphics;

struct {
	Window mainWindow;
} program;

int main(int argc, char* argv[]) {
	//Punji::Graphics::Window window = Punji::Graphics::Window(0, 0, 800, 600, "Bliss Demo", false); //Punji::CreateWindow(0, 0, 800, 600, "Bliss Demo", false);
	program->mainWindow = Window(0,0,800,600,"AHH",false);

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		glfwPollEvents();
	}

	//Punji::DestroyWindow(window);

	return 1;
}