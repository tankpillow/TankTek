#include <TankTek/Window.hpp>
#include <TankTek/Logger.hpp>
#include <TankTek/input/MouseListener.hpp>
#include <TankTek/input/KeyListener.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace TankTek
{
    // Constructor and Destructor
    //---------------------------------------------------------------------------------
    Window::Window()
    {
        this->width = 800;
        this->height = 600;
        this->title = "TankTek";
        this->isRunning = false;
    }

    Window::~Window()
    {
        this->destroy();
    }

    // Setup
    //---------------------------------------------------------------------------------
    void Window::setSize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    void Window::setTitle(const std::string& title)
    {
        this->title = title;
    }

    void Window::setFullscreen(bool fullscreen)
    {
        this->fullscreen = fullscreen;
    }

    void Window::setVsync(bool vsync)
    {
        this->vsync = vsync;
    }

    // Methods
    //---------------------------------------------------------------------------------
    void Window::init()
    {
        TankTek::Logger::info("Initializing GLFW...");
        if (!glfwInit()) {
            TankTek::Logger::error("Failed to initialize GLFW!");
            exit(EXIT_FAILURE);
            return;
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

        if(this->fullscreen) {
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            this->width = mode->width;
            this->height = mode->height;
        }

        this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
        if (!this->window) {
            TankTek::Logger::error("Failed to create GLFW window!");
            glfwTerminate();
            exit(EXIT_FAILURE);
            return;
        }

        glfwSetCursorPosCallback(this->window, MouseListener::mousePosCallback);
        glfwSetMouseButtonCallback(this->window, MouseListener::mouseButtonCallback);
        glfwSetScrollCallback(this->window, MouseListener::mouseScrollCallback);

        glfwSetKeyCallback(this->window, KeyListener::keyCallback);

        glfwMakeContextCurrent(this->window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            TankTek::Logger::error("Failed to initialize GLAD!");
            exit(EXIT_FAILURE);
            return;
        }

        if(this->vsync) {
            glfwSwapInterval(1);
        }

        glfwShowWindow(this->window);
        this->isRunning = true;
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(this->window);
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(this->window);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::destroy()
    {
        glfwDestroyWindow(this->window);
        glfwTerminate();
    }

    void Window::close()
    {
        this->isRunning = false;
    }

}