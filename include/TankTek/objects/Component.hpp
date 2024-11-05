#ifndef TT_Component_HPP_
#define TT_Component_HPP_

namespace TankTek
{
    class Application; 
    class StaticShader;
    class GameObject;

    class Component
    {
        protected:
            GameObject* gameObject;
        public:
            Component(GameObject* gameObject);
            virtual ~Component() = 0;
        public:
            virtual void onStart() = 0;
            virtual void onUpdate() = 0;
            virtual void onRender() = 0;
            virtual void onStop() = 0;
    };
}

#endif