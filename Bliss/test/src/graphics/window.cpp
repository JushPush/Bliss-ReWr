#include <graphics/window.h>

#include <cstring>

namespace Punji::Graphics {
    static void glfwError(int id, const char* description)
    {
        std::cout << description << std::endl;
    }

    Window::~Window() {
        //Destroy();
    }

    bool Window::Init() {
        glfwSetErrorCallback(&glfwError);
        
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize." << std::endl;
            exit(EXIT_FAILURE);
        }

        /*if (!glfwVulkanSupported())
        {
            std::cout << "Vulkan not available." << std::endl;
            return false;
        }*/

        //VulkanInit(data);
        //InitVulkan();

        //glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        //glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
        if (!window) {
            std::cout << "Failed to create window." << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
            //return false;
        }

        // https://www.glfw.org/docs/3.3/vulkan_guide.html

        /*monitor = glfwGetPrimaryMonitor();
        if (monitor == NULL) {
            std::cout << "How did we get here? (failed to find monitor)" << std::endl;
            glfwTerminate();
            return false;
        }*/
        
        glfwMakeContextCurrent(window);

        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        gladLoadGL();
        glfwSwapInterval(0);

        //renderer = Renderer();

        glfwShowWindow(window);
        running = true;

        return true;
    }

    bool Window::SetFullscreen() {
        if (!running) {
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);

            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            window = glfwCreateWindow(mode->width, mode->height, _title.c_str(), monitor, nullptr);
            if (window == NULL) {
                std::cout << "Failed to create window." << std::endl;
                glfwTerminate();
                return false;
            }
        }
        else {
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

            _width = mode->width;
            _height = mode->height;
        }
        fs_current = true;
        return true;
    }

    void Window::Destroy() {
        running = false;
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}