#pragma once

#include "asset.h"

class Shader : public Asset
{
public:
    Shader(const char* path);

    void Load() {}
    void Unload() {}

    void Init();
    void Update();
    void Destroy();

    ~Shader();
};