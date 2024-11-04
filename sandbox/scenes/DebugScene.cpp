#include <sandbox/scenes/DebugScene.hpp>
#include <sandbox/objects/DebugSquare.hpp>

DebugScene::DebugScene() : TankTek::Scene()
{
    
}

DebugScene::~DebugScene()
{

}

void DebugScene::onStart()
{
    TankTek::Logger::info("Debug Scene Started!");

    this->addObject(new DebugSquare());
}

void DebugScene::onUpdate()
{
    TankTek::Scene::onUpdate();   
}   

void DebugScene::onRender()
{
    TankTek::Scene::onRender();
}

void DebugScene::onStop()
{
    TankTek::Logger::info("Debug Scene Stopped!");
}