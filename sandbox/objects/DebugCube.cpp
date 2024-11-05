#include <sandbox/objects/DebugCube.hpp>
#include <TankTek/TankTek.hpp>

DebugCube::DebugCube() : TankTek::GameObject()
{
    TankTek::MeshCube* cube = new TankTek::MeshCube(this);
    TankTek::Texture* texture = TankTek::Application::getInstance()->assetLoader->loadTexture("res/textures/debug.png");

    cube->setTexture(texture);

    this->addComponent(cube);
}

DebugCube::~DebugCube()
{
}

void DebugCube::onStart()
{
}

void DebugCube::onUpdate()
{
    TankTek::GameObject::onUpdate();
    this->rotation.x -= 1.0f;
    this->rotation.y += 1.0f;
    this->rotation.z -= 1.0f;
}

void DebugCube::onRender()
{
    TankTek::GameObject::onRender();
}

void DebugCube::onStop()
{
    
}