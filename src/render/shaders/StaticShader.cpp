#include <TankTek/render/shaders/StaticShader.hpp>
#include <TankTek/objects/Camera.hpp>

namespace TankTek
{
    StaticShader::StaticShader() : ShaderProgram("res/shaders/static_v.glsl", "res/shaders/static_f.glsl")
    {
        this->bindAttributes();
        this->postSetup();
        this->getAllUniformLocations();
    }

    void StaticShader::bindAttributes()
    {
        this->bindAttribute(0, "position");
        this->bindAttribute(1, "texCoord");
    }

    void StaticShader::getAllUniformLocations()
    {
        this->transformationMatrixLocation = this->getUniformLocation("transformationMatrix");  
        this->projectionMatrixLocation = this->getUniformLocation("projectionMatrix"); 
        this->viewMatrixLocation = this->getUniformLocation("viewMatrix");
    }

    void StaticShader::loadTransformationMatrix(const Matrix4& matrix)
    {
        this->loadMatrix(this->transformationMatrixLocation, matrix);
    }

    void StaticShader::loadViewMatrix(const Camera& camera)
    {
        this->loadMatrix(this->viewMatrixLocation, Math::createViewMatrix(camera));
    }

    void StaticShader::loadProjectionMatrix(const Matrix4& matrix)
    {
        this->loadMatrix(this->projectionMatrixLocation, matrix);
    }
}