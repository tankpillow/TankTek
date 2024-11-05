#include <TankTek/objects/GameObject.hpp>
#include <TankTek/objects/Component.hpp>
#include <TankTek/math/Math.hpp>
#include <TankTek/render/shaders/StaticShader.hpp>
#include <TankTek/Application.hpp>

namespace TankTek
{
    GameObject::GameObject()
    {
        this->shader = TankTek::Application::getInstance()->shader;
        this->position = Vector3(0.0f, 0.0f, 0.0f);
        this->rotation = Vector3(0.0f, 0.0f, 0.0f);
        this->scale = Vector3(1.0f, 1.0f, 1.0f);
    }

    GameObject::~GameObject()
    {
        for(auto component : this->components) {
            delete component;
        }
    }

    void GameObject::addComponent(Component* component)
    {
        this->components.push_back(component);
        component->onStart();
    }

    void GameObject::removeComponent(Component* component)
    {
        auto it = std::find(this->components.begin(), this->components.end(), component);
        if(it != this->components.end()) {
            this->components.erase(it);
        }
    }

    void GameObject::onUpdate()
    {
        for(auto component : this->components) {
            component->onUpdate();
        }
    }

    void GameObject::onRender()
    {
        for(auto component : this->components) {
            component->onRender();
        }
    }
}