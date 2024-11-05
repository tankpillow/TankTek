#ifndef TT_GameObject_HPP_
#define TT_GameObject_HPP_

#include <TankTek/math/Math.hpp>
#include <vector>

namespace TankTek
{
    class Component;
    class StaticShader;

    class GameObject
    {
        private:
            std::vector<Component*> components;
            StaticShader* shader;
        public:
            Vector3 position;
            Vector3 rotation;
            Vector3 scale;
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