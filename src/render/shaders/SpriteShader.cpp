#include <TankTek/render/shaders/SpriteShader.hpp>

namespace TankTek
{
    SpriteShader::SpriteShader() : ShaderProgram("res/shaders/sprite_v.glsl", "res/shaders/sprite_f.glsl")
    {
        this->bindAttributes();
    }

    void SpriteShader::bindAttributes()
    {
        this->bindAttribute(0, "position");
        this->bindAttribute(1, "texCoord");
    }
}