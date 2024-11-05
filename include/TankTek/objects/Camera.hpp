#ifndef TT_Camera_HPP_
#define TT_Camera_HPP_

#include <TankTek/math/Math.hpp>

namespace TankTek
{
    class Camera
    {
        public:
            Vector3 position;
            Vector3 rotation;
            Matrix4 projectionMatrix;
        public:
            float fov;
            float nearPlane;
            float farPlane;
        public:
            Camera();
            ~Camera();
        public:
            void onRender();
        public:
            void setPosition(const Vector3& position);
            void setRotation(const Vector3& rotation);
        public:
            Vector3 getPosition() const;
            Vector3 getRotation() const;
            Matrix4 getProjectionMatrix() const;
    };
}

#endif