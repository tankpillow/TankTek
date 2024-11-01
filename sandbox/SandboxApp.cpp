#include <TankTek/TankTek.hpp>

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
        }

        void onUpdate() override
        {
            
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
    return new Sandbox();
}