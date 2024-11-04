#ifndef TT_MouseListener_HPP_
#define TT_MouseListener_HPP_

#include <vector>

class GLFWwindow;

namespace TankTek
{
    class MouseListener
    {
        private:
            static MouseListener* instance;
            double scrollX;
            double scrollY;
            double xPos;
            double yPos;
            double lastX;
            double lastY;
            std::vector<bool> mouseButtons = std::vector<bool>(3); 
            bool dragging;
        private:
            MouseListener();
        public:
            ~MouseListener();
        public:
            static MouseListener* getInstance();
            static void mousePosCallback(GLFWwindow* window, double xPos, double yPos);
            static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
            static void mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
            static void endFrame();
        public:
            double getX();
            double getY();
            double getDX();
            double getDY();
            double getScrollX();
            double getScrollY();
            bool isDragging();
            bool isButtonDown(int button);
    };
}

#endif