#include <sandbox/objects/DebugSquare.hpp>
#include <TankTek/TankTek.hpp>

DebugSquare::DebugSquare()
{
    this->addComponent(new TankTek::PrimitiveMesh(TankTek::PrimitiveType::QUAD));
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

