#pragma once

#include <vector>

class Asset {
public:
    Asset(const char* path) {}

    virtual void Load();
    virtual void Unload();

    virtual ~Asset();

    char* getID() {
        return id;
    }
protected:
private:
    char* id;
};

class AssetManager {
public:
    template<typename T, typename... Args>
    T* addAsset(Args&&... args) {
        T* asset = new T(std::forward<Args>(args)...);
        assets.emplace_back(asset);
        return asset;
    }
    
    template<typename T>
    T* getAsset(const char* id) {
        for (auto asset : assets)
        {
            if (dynamic_cast<T*>(asset)->getID() == id) {
                return static_cast<T*>(asset);
            }
        }
        return nullptr;
    }

private:
    std::vector<Asset*> assets;
};