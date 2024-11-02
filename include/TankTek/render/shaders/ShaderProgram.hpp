#ifndef TT_ShaderProgram_HPP_
#define TT_ShaderProgram_HPP_

#include <string>

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
        public:
            void start();
            void stop();
            void cleanUp();
        protected:
            virtual void bindAttributes() = 0;
            void bindAttribute(int attribute, const std::string& variableName);
        private:
            static unsigned int loadShader(const std::string& file, unsigned int type);
    };
}

#endif