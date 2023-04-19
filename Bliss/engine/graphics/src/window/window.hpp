#pragma once
#pragma ACME path window

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Punji::Graphics
{
    struct Window
    {
    protected:
        int _x, _y, _width, _height; std::string _title;
        bool _fullscreen, _minimized, _resizable;
        GLFWwindow* window;

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
            obj->OnResize(width, height);
        }

        static void window_close_callback(GLFWwindow* window) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->Destroy();
        }

    public:
        Window() noexcept = default;
        Window(int X = 0, int Y = 0, int Width = 800, int Height = 600, std::string Title = "Untitled", bool Fullscreen = false) : _x(X), _y(Y), _width(Width), _height(Height), _title(Title), _fullscreen(Fullscreen) {}
        
        // Destructors acrually suck but I'll keep it just this once
        ~Window();

        bool Init();

        void Destroy();

        bool SetFullscreen();

        void SwapBuffers() { glfwSwapBuffers(window); glClearColor(0.0f,0.0f,0.0f,1.0f), glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glLoadIdentity(); }

        // TODO: put these into multicast delegates bc it's faster :) 
        virtual void OnCreate() {}
        virtual void OnDestroy() {}
        virtual void OnResize(int width, int height) {}
        virtual void Input() {}
        virtual void Update() {}

        int x() const {return _x;} int y() const {return _y;} int width() const {return _width;} int height() const {return _height;}

        GLFWwindow* getWindow() { return window; }
    };
}
