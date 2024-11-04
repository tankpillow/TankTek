#ifndef TT_Scene_HPP_
#define TT_Scene_HPP_

#include <vector>

namespace TankTek
{
    class GameObject;
    class Application;

    class Scene
    {
        protected:
            std::vector<GameObject*> objects;
        public:
            Scene();
            virtual ~Scene();
        public:
            virtual void onStart() = 0;
            virtual void onUpdate();
            virtual void onRender();
            virtual void onStop() = 0;
        protected:
            void addObject(GameObject* object);
            void removeObject(GameObject* object);
    };
}

#endif