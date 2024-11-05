#ifndef TT_Math_HPP_
#define TT_Math_HPP_

#include <glm/glm.hpp>

namespace TankTek
{
    using Vector2 = glm::vec2;
    using Vector3 = glm::vec3;
    using Vector4 = glm::vec4;

    using Matrix2 = glm::mat2;
    using Matrix3 = glm::mat3;
    using Matrix4 = glm::mat4;

    using Transform = glm::mat4;

    class Camera;

    class Math
    {
        public:
            static Transform createTransform(const Vector3& position, const Vector3& rotation, const Vector3& scale);
            static Matrix4 createViewMatrix(const Camera& camera);
    };
}

#endif