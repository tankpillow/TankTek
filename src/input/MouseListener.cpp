#include <TankTek/input/MouseListener.hpp>

#include <GLFW/glfw3.h>

namespace TankTek
{
    MouseListener* MouseListener::instance = nullptr;

    MouseListener::MouseListener()
    {
        this->scrollX = 0.0;
        this->scrollY = 0.0;
        this->xPos = 0.0;
        this->yPos = 0.0;
        this->lastX = 0.0;
        this->lastY = 0.0;
        this->dragging = false;
        this->mouseButtons = std::vector<bool>(GLFW_MOUSE_BUTTON_LAST, false);
    }

    MouseListener::~MouseListener()
    {
        delete instance;
    }

    MouseListener* MouseListener::getInstance()
    {
        if (instance == nullptr) {
            instance = new MouseListener();
        }

        return instance;
    }

    void MouseListener::mousePosCallback(GLFWwindow* window, double xPos, double yPos)
    {
        MouseListener::getInstance()->lastX = MouseListener::getInstance()->xPos;
        MouseListener::getInstance()->lastY = MouseListener::getInstance()->yPos;
        MouseListener::getInstance()->xPos = xPos;
        MouseListener::getInstance()->yPos = yPos;
        MouseListener::getInstance()->dragging = MouseListener::getInstance()->mouseButtons[GLFW_MOUSE_BUTTON_LEFT] || 
                                                 MouseListener::getInstance()->mouseButtons[GLFW_MOUSE_BUTTON_RIGHT] ||
                                                 MouseListener::getInstance()->mouseButtons[GLFW_MOUSE_BUTTON_MIDDLE];
    }

    void MouseListener::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        if(action == GLFW_PRESS) {
            if(button < MouseListener::getInstance()->mouseButtons.size()) {
                MouseListener::getInstance()->mouseButtons[button] = true;
            }
            MouseListener::getInstance()->mouseButtons[button] = true;
        } else if(action == GLFW_RELEASE) {
            MouseListener::getInstance()->mouseButtons[button] = false;
        }
    }

    void MouseListener::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
    {
        MouseListener::getInstance()->scrollX = xOffset;
        MouseListener::getInstance()->scrollY = yOffset;
    }

    void MouseListener::endFrame()
    {
        MouseListener::getInstance()->scrollX = 0.0;
        MouseListener::getInstance()->scrollY = 0.0;
        MouseListener::getInstance()->lastX = MouseListener::getInstance()->xPos;
        MouseListener::getInstance()->lastY = MouseListener::getInstance()->yPos;
    }

    double MouseListener::getX()
    {
        return this->xPos;
    }

    double MouseListener::getY()
    {
        return this->yPos;
    }

    double MouseListener::getDX()
    {
        return this->xPos - this->lastX;
    }

    double MouseListener::getDY()
    {
        return this->yPos - this->lastY;
    }

    double MouseListener::getScrollX()
    {
        return this->scrollX;
    }

    double MouseListener::getScrollY()
    {
        return this->scrollY;
    }

    bool MouseListener::isDragging()
    {
        return this->dragging;
    }

    bool MouseListener::isButtonDown(int button)
    {
        if(button < this->mouseButtons.size()) {
            return this->mouseButtons[button];
        }

        return false;
    }
}