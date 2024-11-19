#include <sandbox/scenes/DebugScene.hpp>
#include <sandbox/objects/DebugSquare.hpp>
#include <sandbox/objects/DebugCube.hpp>
#include <TankTek/Logger.hpp>

#include <GLFW/glfw3.h>

DebugScene::DebugScene() : TankTek::Scene()
{
    
}

DebugScene::~DebugScene()
{

}

void DebugScene::onStart()
{
    TankTek::Logger::info("Debug Scene Started!");

    this->camera = new TankTek::Camera();

    // set mouse mode
    TankTek::MouseListener::getInstance()->setMouseMode(GLFW_CURSOR_DISABLED);

    DebugCube* cube = new DebugCube();
    cube->position = TankTek::Vector3(0.0f, 0.0f, -3.0f);

    this->addObject(cube);
}

void DebugScene::onUpdate()
{
    TankTek::Scene::onUpdate();   

    // Move camera based on key input
    if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_W)) {
        this->camera->position.z -= 0.1f;
    } else if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_S)) {
        this->camera->position.z += 0.1f;
    }

    if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_A)) {
        this->camera->position.x -= 0.1f;
    } else if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_D)) {
        this->camera->position.x += 0.1f;
    }

    // Update camera rotation based on mouse movement
    if(TankTek::MouseListener::getInstance()->isButtonDown(GLFW_MOUSE_BUTTON_RIGHT)) {
        this->camera->rotation.y += TankTek::MouseListener::getInstance()->getDX() * 0.1f;
        this->camera->rotation.x += TankTek::MouseListener::getInstance()->getDY() * 0.1f;
    
    }
}   

void DebugScene::onRender()
{
    TankTek::Scene::onRender();
    this->camera->onRender();
}

void DebugScene::onStop()
{
    TankTek::Logger::info("Debug Scene Stopped!");
}