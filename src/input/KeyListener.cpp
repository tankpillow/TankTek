#include <TankTek/input/KeyListener.hpp>

#include <GLFW/glfw3.h>

namespace TankTek
{
    KeyListener* KeyListener::instance = nullptr;

    KeyListener::KeyListener()
    {
        this->keys = std::vector<bool>(GLFW_KEY_LAST, false);
    }

    KeyListener::~KeyListener()
    {
        delete instance;
    }

    KeyListener* KeyListener::getInstance()
    {
        if (instance == nullptr) {
            instance = new KeyListener();
        }

        return instance;
    }

    void KeyListener::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if(action == GLFW_PRESS) {
            KeyListener::getInstance()->keys[key] = true;
        } else if(action == GLFW_RELEASE) {
            KeyListener::getInstance()->keys[key] = false;
        }
    }

    bool KeyListener::isKeyDown(int key)
    {
        return KeyListener::getInstance()->keys[key];
    }
}