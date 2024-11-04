#ifndef TT_GameObject_HPP_
#define TT_GameObject_HPP_

#include <vector>

namespace TankTek
{
    class Component;

    class GameObject
    {
        private:
            std::vector<Component*> components;
        public:
            GameObject();
            virtual ~GameObject() = 0;
        protected:
            void addComponent(Component* component);
            void removeComponent(Component* component);
        public:
            virtual void onStart() = 0;
            virtual void onUpdate();
            virtual void onRender();
            virtual void onStop() = 0;

    };
}

#endif