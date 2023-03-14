#pragma once

#define MAX_COMPONENTS 32

namespace Punji 
{
    class Entity
    {
    public:
        virtual Entity() = default;

        virtual void Init() = {};
        virtual void Update() = {};
        virtual void Render() = {};
        virtual void Destroy() = {};

        virtual ~Entity();
    };
}