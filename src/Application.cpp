#include <TankTek/Application.hpp>
#include <glad/glad.h>
#include <TankTek/Window.hpp>

namespace TankTek
{
    // Constructor and Destructor
    //---------------------------------------------------------------------------------
    Application::Application()
    {
        this->window = new Window();
    }

    Application::~Application()
    {

    }

    // Methods
    //---------------------------------------------------------------------------------
    void Application::run()
    {
        this->window->init();

        this->onStart();

        while(!this->window->shouldClose()) {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); 
            glClear(GL_COLOR_BUFFER_BIT);

            this->onUpdate();
            this->onRender();

            this->window->swapBuffers();
            this->window->pollEvents();
        }
        this->onStop();
    }
}