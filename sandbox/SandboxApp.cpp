#include <TankTek/TankTek.hpp>

class Sandbox : public TankTek::Application
{
    public:
        Sandbox()
        {
            TankTek::Logger::init(false);
            TankTek::Logger::info("Sandbox Application Started!");
        }

        ~Sandbox()
        {
        }
};

TankTek::Application* TankTek::createApplication()
{
    return new Sandbox();
}