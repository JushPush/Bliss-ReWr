#pragma once

#include <iostream>
#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"

namespace Punji {
    class Window {
    public:
        int x, y, width, height;
        std::string title;
        bool fullscreen;

        bool minimized = false;

        bool resizable = true;

        Window();
        Window(int x, int y, int width, int height, std::string title, bool fullscreen);
        ~Window();

        bool Init();
        void Destroy();

        bool SetFullscreen();

        // User functions



        // Super cool and fun stuff

        GLFWwindow* getWindow() { return window; }
    private:
        bool fs_current = false;
        bool running = false;

        Renderer renderer;

        GLFWwindow* window;
        GLFWmonitor* monitor;

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->input.inputs._keys[key] = (action == GLFW_PRESS);
        }

        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
        {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->input.inputs.mouse.x = xpos;
            //obj->input.inputs.mouse.y = ypos;
        }

        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
        {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->input.inputs._mouse_buttons[button] = (action == GLFW_PRESS);
        }

        static void window_size_callback(GLFWwindow* window, int width, int height) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->Resize(width, height);
        }

        static void window_close_callback(GLFWwindow* window) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->Destroy();
        }
    };
    /*
    /// <summary>
    /// 
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="width"></param>
    /// <param name="height"></param>
    /// <param name="title"></param>
    /// <param name="fullscreen"></param>
    /// <returns>Window Object</returns>
    Window CreateWindow(int x, int y, int width, int height, std::string title, bool fullscreen);
    bool InitWindow(Window& window);
    void DestroyWindow(Window& window);

    bool PollEvents(Window& window);

    bool SetFullscreen(Window& window);

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void window_size_callback(GLFWwindow* window, int width, int height);
    static void window_close_callback(GLFWwindow* window);*/
}