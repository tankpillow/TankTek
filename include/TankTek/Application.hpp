#ifndef TT_Application_HPP_
#define TT_Application_HPP_

namespace TankTek
{
    class Window;

    class Application
    {
        protected: 
            Window* window;
        public: // Constructor and Destructor
            Application();
            virtual ~Application() = 0;
        public: // Callbacks:
            virtual void onStart() = 0;
            virtual void onUpdate() = 0;
            virtual void onRender() = 0;
            virtual void onStop() = 0;
        public: // Methods
            void run();
    };

    // This gets defined in the main.
    Application* createApplication();
}

#endif