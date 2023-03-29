#include <GLFW/glfw3.h>
#include <cstring>
#include <fstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <linmath.h>
#include <string>
#include <unordered_map>
#include <vector>
/*  MIT License

    Copyright (c) 2023 Kara Wilson

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#define GLFW_INCLUDE_NONE

namespace Punji::Graphics {
    class Window {
    public:
        Window(int x = 0, int y = 0, int width = 800, int height = 600, std::string title = "Untitled", bool fullscreen = false) : _x(x), _y(y), _width(width), _height(height), _title(title), _fullscreen(fullscreen) { Init(); }
        ~Window();

        bool Init();

        void Destroy();

        bool SetFullscreen();

        void SwapBuffers() { glfwSwapBuffers(window); }

        virtual void OnCreate() {}

        virtual void OnDestroy() {}

        virtual void OnResize(int width, int height) {}

        virtual void Input() {}

        virtual void Update() {}

        bool ShouldClose() { return glfwWindowShouldClose(window); }

        GLFWwindow* getWindow() { return window; }
        std::string getTitle() { return _title; }
        bool isRunning() { return running; }
        bool isMinimized() { return minimized; }
        int getWidth() { return _width; }
        int getHeight() { return _height; }
    private:
        int _x, _y, _width, _height;
        std::string _title;
        bool _fullscreen;

        bool running = false;
        bool minimized = false;
        bool resizable = true;
        bool fs_current = false;

        GLFWwindow* window;
        GLFWmonitor* monitor;

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
        }

        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
        {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
        }

        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
        {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
        }

        static void window_size_callback(GLFWwindow* window, int width, int height) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
            obj->OnResize(width, height);
        }

        static void window_close_callback(GLFWwindow* window) {
            Window* obj = (Window*)glfwGetWindowUserPointer(window);
        }
    };
}namespace Punji::Engine
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
struct OBJIndex
{
    unsigned int vertexIndex;
    unsigned int uvIndex;
    unsigned int normalIndex;
    
    bool operator<(const OBJIndex& r) const { return vertexIndex < r.vertexIndex; }
};

class IndexedModel
{
public:
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;
    std::vector<glm::vec3> normals;
    std::vector<unsigned int> indices;
    
    void CalcNormals();
};

class OBJModel
{
public:
    std::vector<OBJIndex> OBJIndices;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    bool hasUVs;
    bool hasNormals;
    
    OBJModel(const std::string& fileName);
    
    IndexedModel ToIndexedModel();
private:
    unsigned int FindLastVertexIndex(const std::vector<OBJIndex*>& indexLookup, const OBJIndex* currentIndex, const IndexedModel& result);
    void CreateOBJFace(const std::string& line);
    
    glm::vec2 ParseOBJVec2(const std::string& line);
    glm::vec3 ParseOBJVec3(const std::string& line);
    OBJIndex ParseOBJIndex(const std::string& token, bool* hasUVs, bool* hasNormals);
};enum MeshBufferPositions
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
}namespace Punji {
	class Camera : public Punji::Engine::Entity {
	public:
		Camera() {}

		void Init() {}
		void Update() {}
		void Render() {}

		~Camera() {}

		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
		glm::mat4 projection;
	};
}namespace Punji::Engine
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
            glm::mat4 posMat = glm::translate(pos);
            glm::mat4 scaleMat = glm::scale(scale);
            glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
            glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
            glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
            glm::mat4 rotMat = rotX * rotY * rotZ;

            return posMat * rotMat * scaleMat;
        }

        inline glm::mat4 GetMVP(const Camera& camera) const
        {
            glm::mat4 VP = GetViewProjection(camera);
            glm::mat4 M = GetModel();

            return VP * M;//camera.GetViewProjection() * GetModel();
        }
    };
}namespace Punji::Engine
{
    class ShaderComponent : public Component {
    public:
        ShaderComponent(std::string fileName);

        GLuint program;
        GLuint shaders[2];
        GLuint uniforms[3];

        void Bind();
        void Update(const Camera& camera);
        void Render() {};

        void Unload();

        GLuint GLCreateShader(const std::string& text, unsigned int type);
        std::string LoadShaderSRC(const std::string& fileName);
        void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    };
}namespace Punji::Engine {
    class TextureComponent : Component {
    public:
        TextureComponent();
    };
}namespace Punji::Engine
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
namespace Punji {
	class Camera : public Punji::Engine::Entity {
	public:
		Camera() {}

		void Init() {}
		void Update() {}
		void Render() {}

		~Camera() {}

		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
		glm::mat4 projection;
	};
}namespace Punji::Engine
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
