#ifndef TT_Application_HPP_
#define TT_Application_HPP_

namespace TankTek
{
    class Application
    {
        public: // Constructor and Destructor
            Application();
            ~Application();
        public: // Methods
            void run();
    };

    // This gets defined in the main.
    Application* createApplication();
}

#endif