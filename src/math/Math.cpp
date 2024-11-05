#include <TankTek/math/Math.hpp>
#include <TankTek/objects/Camera.hpp> 

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace TankTek
{
    Transform Math::createTransform(const Vector3& position, const Vector3& rotation, const Vector3& scale)
    {
        Transform transform = glm::mat4(1.0f);
        transform = glm::translate(transform, position);
        transform = glm::rotate(transform, glm::radians(rotation.x), Vector3(1.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.y), Vector3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.z), Vector3(0.0f, 0.0f, 1.0f));
        transform = glm::scale(transform, scale);

        return transform;
    }

    Matrix4 Math::createViewMatrix(const Camera& camera)
    {
        Matrix4 viewMatrix = glm::mat4(1.0f);
        viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRotation().x), Vector3(1.0f, 0.0f, 0.0f));
        viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRotation().y), Vector3(0.0f, 1.0f, 0.0f));
        viewMatrix = glm::rotate(viewMatrix, glm::radians(camera.getRotation().z), Vector3(0.0f, 0.0f, 1.0f));

        Vector3 cameraPos = camera.getPosition();
        Vector3 negativeCameraPos = -camera.getPosition();
        
        viewMatrix = glm::translate(viewMatrix, negativeCameraPos);

        return viewMatrix;
    }
}