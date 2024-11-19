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
            if(TankTek::KeyListener::getInstance()->isKeyDown(GLFW_KEY_ESCAPE)) {
                exit(0);
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