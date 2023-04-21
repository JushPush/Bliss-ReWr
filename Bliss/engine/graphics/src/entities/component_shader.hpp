#ifndef COMPSHAD_HPP
#define COMPSHAD_HPP

#include <bliss_core.hpp>

#include <iostream>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "camera.hpp"

#include "component_transform.hpp"

namespace Punji::Graphics
{
    class ShaderComponent : public Punji::Core::Component {
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


#endif