#ifndef TT_StaticShader_HPP_
#define TT_StaticShader_HPP_

#include <TankTek/render/shaders/ShaderProgram.hpp>

namespace TankTek
{
    class Camera; 

    class StaticShader : public ShaderProgram
    {
        private:
            unsigned int transformationMatrixLocation;
            unsigned int projectionMatrixLocation;
            unsigned int viewMatrixLocation;
        public:
            StaticShader();
        protected:
            void bindAttributes() override;
            void getAllUniformLocations() override;
        public:
            void loadTransformationMatrix(const Matrix4& matrix);
            void loadProjectionMatrix(const Matrix4& matrix);
            void loadViewMatrix(const Camera& camera);
    };
}

#endif