#include <Bliss.h>

// ImGui integration
#include <common/imgui/imgui.h>
#include <math.h>

int main(int argc, char* argv[]) {
	Punji::Window window = Punji::Window(0, 0, 800, 600, "Bliss Demo", false); //Punji::CreateWindow(0, 0, 800, 600, "Bliss Demo", false);

	//Punji::InitWindow(window);

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		glfwPollEvents();
	}

	//Punji::DestroyWindow(window);

	return 1;
}