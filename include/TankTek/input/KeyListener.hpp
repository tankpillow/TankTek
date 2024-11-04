#ifndef TT_KeyListener_HPP_
#define TT_KeyListener_HPP_

#include <vector>

class GLFWwindow;

namespace TankTek
{
    class KeyListener
    {
        private:
            static KeyListener* instance;
            std::vector<bool> keys;
        private:
            KeyListener();
        public:
            ~KeyListener();
        public:
            static KeyListener* getInstance();
            static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        public:
            bool isKeyDown(int key);
    };
}

#endif