#pragma once

#include "asset.h"

namespace Punji
{
    class Texture : public Asset {
        Texture(const char* path);
        ~Texture();

        void Init();
        void Update();
    };
}