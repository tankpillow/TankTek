#include <TankTek/render/shaders/StaticShader.hpp>

namespace TankTek
{
    StaticShader::StaticShader() : ShaderProgram("res/shaders/vertexShader.glsl", "res/shaders/fragmentShader.glsl")
    {
        this->bindAttributes();
    }

    void StaticShader::bindAttributes()
    {
        this->bindAttribute(0, "position");
    }
}