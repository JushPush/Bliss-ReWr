#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

#include "stb_image.h"

#include "../entity.hpp"

namespace Punji::Core
{
    class TextureComponent : public Component {
    public:
        TextureComponent(std::string fileName);

        GLuint texture;

        void Init() {};
        void Bind();
        void Render() {};
        void Unload();
    };
}