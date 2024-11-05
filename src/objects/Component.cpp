#include <TankTek/objects/Component.hpp>
#include <TankTek/Application.hpp>

namespace TankTek
{
    Component::Component(GameObject* gameObject) : gameObject(gameObject)
    {}

    Component::~Component()
    {}
}