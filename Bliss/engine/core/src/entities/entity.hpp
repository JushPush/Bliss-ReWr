#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#pragma ACME path entities

#include <vector>
#include <string>
#include <glm/glm.hpp>

namespace Punji::Core
{
    class Component;
    class Entity;

    class Component {
    public:
        virtual ~Component() = default;
        Entity* entity;
    };

    class Entity {
    public:
        virtual void Init() {}
        virtual void Update() {}
        virtual void Render() {}

        template<typename T, typename... Args>
        T* addComponent(Args&&... args) {
            T* component = new T(std::forward<Args>(args)...);
            component->entity = this;
            components.emplace_back(component);
            return component;
        }

        template<typename T>
        T* addComponent() {
            T* component = new T();
            component->entity = this;
            components.emplace_back(component);
            return component;
        }

        template<typename T>
        T* getComponent() const {
            for (auto component : components) {
                if (dynamic_cast<T*>(component)) {
                    return static_cast<T*>(component);
                }
            }
            return nullptr;
        }

        void Destroy() {
            for (auto component : components) {
                component->entity = nullptr;
                delete component;
            }
            components.clear();
        }

    private:
        std::vector<Component*> components;
    };
}

#endif