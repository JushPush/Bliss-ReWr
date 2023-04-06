#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../entity.hpp"

namespace Punji::Core
{
    class TransformComponent : public Component {
    public:
        TransformComponent() {}
        glm::vec3 pos;
        glm::vec3 rot;
        glm::vec3 scale;

        inline glm::mat4 GetViewProjection(const Camera& camera) const 
        {
            return camera.projection * glm::lookAt(camera.pos, camera.pos + camera.forward, camera.up);
        }

        inline glm::mat4 GetModel() const
        {
            //glm::mat4 posMat = glm::translate(pos);
            //glm::mat4 scaleMat = glm::scale(scale);
            //glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
            //glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
            //glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
            //glm::mat4 rotMat = rotX * rotY * rotZ;

            return NULL;//posMat * rotMat * scaleMat;
        }

        inline glm::mat4 GetMVP(const Camera& camera) const
        {
            glm::mat4 VP = GetViewProjection(camera);
            glm::mat4 M = GetModel();

            return VP * M;//camera.GetViewProjection() * GetModel();
        }
    };
}