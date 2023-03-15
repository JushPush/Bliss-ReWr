#pragma once

#include <iostream>
#include <string>
#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "renderer.h"

#include "api/api_vulkan.h"

namespace Punji::Graphics {
    class Window {
    public:
        Window() : _x(0), _y(0), _width(800), _height(600), _title("Untitled") { Init(); }
        Window(int x, int y, int width, int height, std::string title, bool fullscreen) : _x(x), _y(y), _width(width), _height(height), _title(title), _fullscreen(fullscreen) { Init(); }
        ~Window();

        bool Init();
        void Destroy();
        bool SetFullscreen();
        
        void ClearBuffer();

        void InitVulkan();

        // Events
        virtual void OnCreate() {}
        virtual void OnDestroy() {}

        // User Functions
        virtual void Input() {}
        virtual void Update() {}
       

        // Get private variables
        GLFWwindow* getWindow() { return window; }
        std::string getTitle() { return _title; }
        bool isRunning() { return running; }
        bool isMinimized() { return minimized; }
    private:
        int _x, _y, _width, _height;
        std::string _title;
        bool _fullscreen;

        bool running = false;
        bool minimized = false;
        bool resizable = true;
        bool fs_current = false;

        Renderer renderer;

        GLFWwindow* window;
        GLFWmonitor* monitor;
        
        bl_VulkanData data;

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
}