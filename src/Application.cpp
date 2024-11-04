#include <TankTek/Application.hpp>
#include <glad/glad.h>

#include <TankTek/Window.hpp>
#include <TankTek/render/Renderer.hpp>
#include <TankTek/render/AssetLoader.hpp>
#include <TankTek/Scene.hpp>
#include <TankTek/render/shaders/StaticShader.hpp>

namespace TankTek
{
    Application* Application::instance = nullptr;

    // Constructor and Destructor
    //---------------------------------------------------------------------------------
    Application::Application()
    {
        this->window = new Window();
        this->renderer = new Renderer();
        this->assetLoader = new AssetLoader();
        this->shader = nullptr;
        this->scene = nullptr;
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
            if(this->scene != nullptr) {
                this->scene->onUpdate();
            }
            
            this->shader->start();
            this->onRender();
            if(this->scene != nullptr) { 
                this->scene->onRender();
            }
            this->shader->stop();

            this->window->swapBuffers();
            this->window->pollEvents();
        }

        this->shader->cleanUp();
        this->assetLoader->cleanUp();

        this->onStop();
    }

    void Application::setScene(Scene* scene)
    {
        if(this->scene != nullptr) {
            this->scene->onStop();
        }

        this->scene = scene;
        
        this->scene->onStart();
    }

    Application* Application::getInstance()
    {
        if(Application::instance == nullptr) {
            Application::instance = createApplication();
        }
        return Application::instance;
    }
}