#include <TankTek/EntryPoint.hpp>
#include <TankTek/TankTek.hpp>
#include <sandbox/scenes/DebugScene.hpp>    

#include <GLFW/glfw3.h>

#include <vector>

class Sandbox : public TankTek::Application
{
    public:
        Sandbox() : TankTek::Application()
        {
            TankTek::Logger::init(false);

            this->window->setSize(1280, 720);
            this->window->setTitle("SandboxApp");
            this->window->setFullscreen(false);
            this->window->setVsync(true);
        }

        ~Sandbox()
        {

        }

        void onStart() override
        {
            TankTek::Logger::info("Sandbox Application Started!");
            this->setScene(new DebugScene());
        }

        void onUpdate() override
        {
            if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_SPACE)) {
                TankTek::Logger::info("Space key is down!");
            }

            if(TankTek::MouseListener::getInstance()->isButtonDown(GLFW_MOUSE_BUTTON_LEFT)) {
                int x = TankTek::MouseListener::getInstance()->getX();
                int y = TankTek::MouseListener::getInstance()->getY();
                TankTek::Logger::info("Mouse is at: " + std::to_string(x) + ", " + std::to_string(y));
            }

        }

        void onRender() override
        {
            
        }

        void onStop() override
        {
            TankTek::Logger::info("Sandbox Application Stopped!");
        }
};

TankTek::Application* TankTek::createApplication()
{
    Application* app = new Sandbox();
    TankTek::Application::instance = app;
    return app;
}