#pragma once

#pragma PYCHAS path engine/entities/ecs

#include <linmath.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <string>
#include <vector>
#include <cstring>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../entity.h"
#include "obj_loader.h"

enum MeshBufferPositions
{
	POSITION_VB,
	TEXCOORD_VB,
	NORMAL_VB,
	INDEX_VB
};

namespace Punji::Engine {
    class MeshComponent : public Component {
    public:
        MeshComponent(std::string fileName);
        //MeshComponent(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);

        GLuint VAO;
        GLuint VBO[4];
        unsigned int numIndices;
        unsigned int *indices;

        void Init() {};
        void Bind() {};
        void Unload() {};

        void InitMesh(const IndexedModel& model);

        void Render();
    };
}