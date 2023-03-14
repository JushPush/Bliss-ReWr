#pragma once

namespace Punji 
{
    class Component {
    public:
        virtual Component() = default;

        virtual void Init();
        virtual void Update();
        virtual void Render();
        virtual void Delete();
    };
}