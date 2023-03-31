/*  MIT License

    Copyright (c) 2023 Kara Wilson

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

///
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Punji::Graphics {
    class Window {
    public:
        Window(int x = 0, int y = 0, int width = 800, int height = 600, std::string title = "Untitled", bool fullscreen = false) : _x(x), _y(y), _width(width), _height(height), _title(title), _fullscreen(fullscreen) { Init(); }
        ~Window();

        /// @brief Init Window
        /// @return Success
        bool Init();

        /// @brief Destroy Window
        void Destroy();

        /// @brief Set Window to fullscreen
        /// @return Success
        bool SetFullscreen();

        /// @brief Does a thing
        void SwapBuffers() { glfwSwapBuffers(window); glClearColor(0.0f, 0.0f, 0.0f, 1.0f ); glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glLoadIdentity(); }

        /// @brief Create Event
        virtual void OnCreate() {}

        /// @brief Destroy Event
        virtual void OnDestroy() {}

        /// @brief Resize Event
        virtual void OnResize(int width, int height) {}

        /// @brief OPTIONAL : Use for handling input events
        virtual void Input() {}

        /// @brief Update
        virtual void Update() {}

        bool ShouldClose() { return glfwWindowShouldClose(window); }

        /// @brief Return GLFWwindow
        GLFWwindow* getWindow() { return window; }
        std::string getTitle() { return _title; }
        bool isRunning() { return running; }
        bool isMinimized() { return minimized; }
        int getWidth() { return _width; }
        int getHeight() { return _height; }
    private:
        int _x, _y, _width, _height;
        std::string _title;
        bool _fullscreen;

        bool running = false;
        bool minimized = false;
        bool resizable = true;
        bool fs_current = false;

        //Renderer renderer;

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
            obj->OnResize(width, height);
        }

        static void window_close_callback(GLFWwindow* window) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            //obj->Destroy();
        }
    };
}