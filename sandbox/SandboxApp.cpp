#include <TankTek/TankTek.hpp>

#include <GLFW/glfw3.h>

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