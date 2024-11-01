#ifndef TT_Window_HPP_
#define TT_Window_HPP_

#include <string>

class GLFWwindow;

namespace TankTek
{
    class Window
    {
        private:
            int width;
            int height;
            std::string title;
            bool fullscreen;
            bool vsync;
        private:
            GLFWwindow* window;
        public: // Constructor and Destructor
            Window();
            ~Window();
        public: // Setup
            void setSize(int width, int height);
            void setTitle(const std::string& title);
            void setFullscreen(bool fullscreen);
            void setVsync(bool vsync);
        public: // Methods
            void init();
            bool shouldClose();
            void swapBuffers();
            void pollEvents();
            void destroy();
        
    };
}

#endif