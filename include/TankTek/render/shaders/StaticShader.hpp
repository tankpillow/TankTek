#ifndef TT_StaticShader_HPP_
#define TT_StaticShader_HPP_

#include <TankTek/render/shaders/ShaderProgram.hpp>

namespace TankTek
{
    class StaticShader : public ShaderProgram
    {
        public:
            StaticShader();
        protected:
            void bindAttributes() override;
    };
}

#endif