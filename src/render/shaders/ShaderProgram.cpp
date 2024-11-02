#include <TankTek/render/shaders/ShaderProgram.hpp>
#include <TankTek/Logger.hpp>

#include <glad/glad.h>

#include <sstream>
#include <fstream>

namespace TankTek
{

    ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        this->vertexShaderID = loadShader(vertexShaderFile, GL_VERTEX_SHADER);
        this->fragmentShaderID = loadShader(fragmentShaderFile, GL_FRAGMENT_SHADER);

        this->programID = glCreateProgram();
        glAttachShader(this->programID, this->vertexShaderID);
        glAttachShader(this->programID, this->fragmentShaderID);
        glLinkProgram(this->programID);
        glValidateProgram(this->programID);
        this->bindAttributes();
    }

    void ShaderProgram::start()
    {
        glUseProgram(this->programID);
    }

    void ShaderProgram::stop()
    {
        glUseProgram(0);
    }

    void ShaderProgram::cleanUp()
    {
        stop();
        glDetachShader(this->programID, this->vertexShaderID);
        glDetachShader(this->programID, this->fragmentShaderID);

        glDeleteShader(this->vertexShaderID);
        glDeleteShader(this->fragmentShaderID);
        glDeleteProgram(this->programID);
    }

    void ShaderProgram::bindAttribute(int attribute, const std::string& variableName)
    {
        glBindAttribLocation(this->programID, attribute, variableName.c_str());
    }

    unsigned int ShaderProgram::loadShader(const std::string& filePath, unsigned int type)
    {
        std::ifstream file(filePath);
        if(!file.is_open()) {
            std::stringstream ss;
            ss << "Failed to open file: " << filePath;
            Logger::error(ss.str());
            return 0;
        }

        std::string source;
        std::string line;
        while(std::getline(file, line)) {
            source += line + "\n";
        }

        file.close();

        unsigned int shaderID = glCreateShader(type);
        const char* src = source.c_str();
        glShaderSource(shaderID, 1, &src, nullptr);
        glCompileShader(shaderID);
        if(!shaderID) {
            int length;
            glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &length);
            char* message = (char*)alloca(length * sizeof(char));
            glGetShaderInfoLog(shaderID, length, &length, message);
            std::stringstream ss;
            ss << "Failed to compile shader: " << message;
            Logger::error(ss.str());
            return 0;
        }

        return shaderID;
    }
}