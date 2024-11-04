#ifndef TT_StaticShader_HPP_
#define TT_StaticShader_HPP_

#include <TankTek/render/shaders/ShaderProgram.hpp>

namespace TankTek
{
    class SpriteShader : public ShaderProgram
    {
        public:
            SpriteShader();
        protected:
            void bindAttributes() override;
    };
}

#endif