#include <TankTek/Scene.hpp>

#include <TankTek/Application.hpp>
#include <TankTek/objects/GameObject.hpp>

namespace TankTek
{
    Scene::Scene()
    {}

    Scene::~Scene()
    {}

    void Scene::onUpdate()
    {
        for(auto object : this->objects) {
            object->onUpdate();
        }
    }

    void Scene::onRender()
    {
        for(auto object : this->objects) {
            object->onRender();
        }
    }

    void Scene::addObject(GameObject* object)
    {
        this->objects.push_back(object);
        this->objects.back()->onStart();
    }

    void Scene::removeObject(GameObject* object)
    {
        auto it = std::find(this->objects.begin(), this->objects.end(), object);
        if(it != this->objects.end()) {
            this->objects.erase(it);
        }
    }
}