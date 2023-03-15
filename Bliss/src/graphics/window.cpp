#include <graphics/window.h>

#include <cstring>

namespace Punji::Graphics {
    static void glfwError(int id, const char* description)
    {
        std::cout << description << std::endl;
    }

    Window::~Window() {
        Destroy();
    }

    bool Window::Init() {
        glfwSetErrorCallback(glfwError);
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize." << std::endl;
            glfwTerminate();
            return false;
        }

        if (!glfwVulkanSupported())
        {
            std::cout << "Vulkan not available." << std::endl;
            return false;
        }

        //data = bl_VulkanData;

        VulkanInit(data);
        //InitVulkan();

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        // https://www.glfw.org/docs/3.3/vulkan_guide.html


        monitor = glfwGetPrimaryMonitor();
        if (monitor == NULL) {
            std::cout << "How did we get here? (failed to find monitor)" << std::endl;
            glfwTerminate();
            return false;
        }
        
        if (_fullscreen) {
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

            fs_current = true;
        }
        else {
            window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
            if (window == NULL) {
                std::cout << "Failed to create window." << std::endl;
                glfwTerminate();
                return false;
            }
        }

        window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
        if (window == NULL) {
            std::cout << "Failed to create window." << std::endl;
            glfwTerminate();
            return false;
        }

        //glfwMakeContextCurrent(window);

        //renderer = Renderer();
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

    void Window::InitVulkan() {
        
    }

    void Window::ClearBuffer() {
        //glfwSwapBuffers(window);
    }

    /*Window CreateWindow(int x, int y, int width, int height, std::string title, bool fullscreen) {
        return Window{
            x, y, width, height, title, fullscreen
        };
    }

    bool InitWindow(Window& window)
    {
        if (!glfwInit()) {
            std::cout << "GLFW failed to initialize." << std::endl;
            glfwTerminate();
            return false;
        }

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

        window.monitor = glfwGetPrimaryMonitor();
        if (window.monitor == NULL) {
            std::cout << "How did we get here? (failed to find monitor)" << std::endl;
            glfwTerminate();
            return false;
        }

        if (window.fullscreen) {
            const GLFWvidmode* mode = glfwGetVideoMode(window.monitor);

            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            window.window = glfwCreateWindow(mode->width, mode->height, window.title.c_str(), window.monitor, nullptr);
            if (window.window == NULL) {
                std::cout << "Failed to create window." << std::endl;
                glfwTerminate();
                return false;
            }

            window.fs_current = true;
        }
        else {
            window.window = glfwCreateWindow(window.width, window.height, window.title.c_str(), nullptr, nullptr);
            if (window.window == NULL) {
                std::cout << "Failed to create window." << std::endl;
                glfwTerminate();
                return false;
            }
        }

        glfwMakeContextCurrent(window.window);

        window.renderer = Renderer();
        window.running = true;
    }

    void DestroyWindow(Window& window)
    {
        window.running = false;
        glfwDestroyWindow(window.window);
        glfwTerminate();
    }

    bool PollEvents(Window& window)
    {
        if (glfwWindowShouldClose(window.window)) {
            DestroyWindow(window);
            return false;
        }

        if (window.fullscreen && !window.fs_current) {
            SetFullscreen(window);
        }
        else {
            // TODO: Allow exiting fullscreen
        }

        glfwPollEvents();

        return true;
    }

    bool SetFullscreen(Window& window) {
        if (!window.running) {
            const GLFWvidmode* mode = glfwGetVideoMode(window.monitor);

            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            window.window = glfwCreateWindow(mode->width, mode->height, window.title.c_str(), window.monitor, nullptr);
            if (window.window == NULL) {
                std::cout << "Failed to create window." << std::endl;
                glfwTerminate();
                return false;
            }
        }
        else {
            const GLFWvidmode* mode = glfwGetVideoMode(window.monitor);
            glfwSetWindowMonitor(window.window, window.monitor, 0, 0, mode->width, mode->height, mode->refreshRate);

            window.width = mode->width;
            window.height = mode->height;
        }
        window.fs_current = true;
    }*/

    
}