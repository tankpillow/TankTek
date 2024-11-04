#ifndef TT_Application_HPP_
#define TT_Application_HPP_

namespace TankTek
{
    class Window;
    class Renderer;
    class ModelLoader;
    class StaticShader;
    class Scene;

    class Application
    {
        public:
            static Application* instance;
        public: 
            Window* window;
            Renderer* renderer;
            ModelLoader* modelLoader;
            StaticShader* shader;
            Scene* scene;
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
            void setScene(Scene* scene);
        public:
            static Application* getInstance();
    };

    // This gets defined in the main.
    Application* createApplication();
}

#endif