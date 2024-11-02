#include <TankTek/TankTek.hpp>

#include <vector>

class Sandbox : public TankTek::Application
{
    private:
        TankTek::RawModel* model;
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

            std::vector<float> vertices = {
                -0.5f, 0.5f, 0.0f,
                -0.5f, -0.5f, 0.0f,
                0.5f, -0.5f, 0.0f,
                0.5f, 0.5f, 0.0f,
            };

            std::vector<unsigned int> indices = {
                0, 1, 3,
                3, 1, 2
            };

            this->model = this->modelLoader->loadToVAO(vertices, indices);
        }

        void onUpdate() override
        {
            
        }

        void onRender() override
        {
            this->renderer->render(this->model);
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