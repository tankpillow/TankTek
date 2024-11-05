#ifndef TT_ShaderProgram_HPP_
#define TT_ShaderProgram_HPP_

#include <string>
#include <TankTek/math/Math.hpp>

namespace TankTek
{
    class ShaderProgram
    {
        private:
            unsigned int programID;
            unsigned int vertexShaderID;
            unsigned int fragmentShaderID;
        public:
            ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
            void postSetup();
        public:
            void start();
            void stop();
            void cleanUp();
        protected:
            virtual void bindAttributes() = 0;
            void bindAttribute(int attribute, const std::string& variableName);
        protected:
            unsigned int getUniformLocation(const std::string& uniformName);
            void loadFloat(unsigned int location, float value);
            void loadVector(unsigned int location, const Vector3& vector);
            void loadBoolean(unsigned int location, bool value);
            void loadMatrix(unsigned int location, const Matrix4& matrix);
        private:
            virtual void getAllUniformLocations() = 0;
            static unsigned int loadShader(const std::string& file, unsigned int type);
    };
}

#endif