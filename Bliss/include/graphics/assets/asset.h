#pragma once

class Asset {
public:
    virtual Asset(const char* path) {}

    virtual void Load();
    virtual void Unload();

    virtual void Init() = {};
    virtual void Update() = {};
    virtual void Destroy() = {};

    virtual ~Asset();
};