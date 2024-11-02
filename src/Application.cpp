#include <TankTek/Application.hpp>
#include <glad/glad.h>

#include <TankTek/Window.hpp>
#include <TankTek/render/Renderer.hpp>
#include <TankTek/render/ModelLoader.hpp>
#include <TankTek/render/shaders/StaticShader.hpp>

namespace TankTek
{
    // Constructor and Destructor
    //---------------------------------------------------------------------------------
    Application::Application()
    {
        this->window = new Window();
        this->renderer = new Renderer();
        this->modelLoader = new ModelLoader();
    }

    Application::~Application()
    {

    }

    // Methods
    //---------------------------------------------------------------------------------
    void Application::run()
    {
        this->window->init();

        this->shader = new StaticShader();

        this->onStart();

        while(!this->window->shouldClose()) {
            this->renderer->prepareFrame(); 

            this->onUpdate();
            
            this->shader->start();
            this->onRender();
            this->shader->stop();

            this->window->swapBuffers();
            this->window->pollEvents();
        }

        this->shader->cleanUp();
        this->modelLoader->cleanUp();

        this->onStop();
    }
}