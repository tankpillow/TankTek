#include <TankTek/objects/Camera.hpp>
#include <TankTek/render/shaders/StaticShader.hpp>
#include <TankTek/Logger.hpp>

#include <TankTek/Application.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace TankTek
{
    Camera::Camera()
    {
        this->position = Vector3(0.0f, 0.0f, 0.0f);
        this->rotation = Vector3(0.0f, 0.0f, 0.0f);

        this->fov = 70.0f;
        this->nearPlane = 0.1f;
        this->farPlane = 1000.0f;

        this->projectionMatrix = glm::perspective(glm::radians(this->fov), 16.0f / 9.0f, this->nearPlane, this->farPlane);

        TankTek::Application::getInstance()->shader->start();
        TankTek::Application::getInstance()->shader->loadProjectionMatrix(this->projectionMatrix);
        TankTek::Application::getInstance()->shader->stop();
    }

    Camera::~Camera()
    {
    }

    void Camera::onRender()
    {
        TankTek::Application::getInstance()->shader->loadViewMatrix(*this);
    }

    void Camera::setPosition(const Vector3& position)
    {
        this->position = position;
    }

    void Camera::setRotation(const Vector3& rotation)
    {
        this->rotation = rotation;
    }

    Vector3 Camera::getPosition() const
    {
        return this->position;
    }

    Vector3 Camera::getRotation() const
    {
        return this->rotation;
    }


    Matrix4 Camera::getProjectionMatrix() const
    {
        return this->projectionMatrix;
    }
}