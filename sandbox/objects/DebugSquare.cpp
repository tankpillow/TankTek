#include <sandbox/objects/DebugSquare.hpp>
#include <TankTek/TankTek.hpp>

DebugSquare::DebugSquare()
{
    TankTek::Sprite* sprite = new TankTek::Sprite();
    TankTek::Texture* texture = TankTek::Application::getInstance()->assetLoader->loadTexture("res/textures/debug.png");

    sprite->setTexture(texture);

    this->addComponent(sprite);
}

DebugSquare::~DebugSquare()
{
}

void DebugSquare::onStart()
{
}

void DebugSquare::onUpdate()
{
    TankTek::GameObject::onUpdate();
}

void DebugSquare::onRender()
{
    TankTek::GameObject::onRender();
}

void DebugSquare::onStop()
{
    
}

