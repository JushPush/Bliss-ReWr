#include <engine/entities/ecs/component_mesh.h>

namespace Punji::Engine {
    MeshComponent::MeshComponent(std::string fileName)
    {
        InitMesh(OBJModel(fileName).ToIndexedModel());
    }

    void MeshComponent::InitMesh(const IndexedModel& model)
    {
        numIndices = model.indices.size();

        glGenVertexArrays(1, &VAO);
        glBindVertexArray(VAO);

        glGenBuffers(4 /* number o' buffer :)*/, VBO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO[POSITION_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.positions[0]) * model.positions.size(), &model.positions[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[TEXCOORD_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, VBO[NORMAL_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO[INDEX_VB]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);

        glBindVertexArray(0);
    }

    void MeshComponent::Render() {
        glBindVertexArray(VAO);

        glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}