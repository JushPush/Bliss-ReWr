#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "component_transform.hpp"

#include "../entity.hpp"

namespace Punji::Core
{
    class ShaderComponent : public Component {
    public:
        ShaderComponent(std::string fileName);

        GLuint program;
        GLuint shaders[2];
        GLuint uniforms[3];

        void Bind();
        void Update(const Camera& camera);
        void Render() {};

        void Unload();

        GLuint GLCreateShader(const std::string& text, unsigned int type);
        std::string LoadShaderSRC(const std::string& fileName);
        void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    };
}