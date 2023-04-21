#ifndef COMPTEX_HPP
#define COMPTEX_HPP

#include <bliss_core.hpp>

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "stb_image.h"

namespace Punji::Graphics
{
    class TextureComponent : public Punji::Core::Component {
    public:
        TextureComponent(std::string fileName);

        GLuint texture;

        void Init() {};
        void Bind();
        void Render() {};
        void Unload();
    };
}


#endif