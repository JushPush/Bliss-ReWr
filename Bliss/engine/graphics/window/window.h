#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Punji::Graphics
{
    struct Window
    {
        int _x, _y, _width, _height; std::string _title;
        bool fullscreen, minimized, resizable;
        GLFWwindow* window;
    
    public:
        Window() noexcept = default;

        ~Window();

        int x() const {return _x;} int y() const {return _y;} int width() const {return _width;} int height() const {return _height;}

        GLFWwindow* getWindow() { return window; }
    };
}
