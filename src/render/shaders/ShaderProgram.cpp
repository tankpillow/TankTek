#include <TankTek/render/shaders/ShaderProgram.hpp>
#include <TankTek/Logger.hpp>

#include <glad/glad.h>

#include <sstream>
#include <fstream>

namespace TankTek
{

    ShaderProgram::ShaderProgram(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
    {
        TankTek::Logger::info("Loading Shader Program...");
        this->vertexShaderID = loadShader(vertexShaderFile, GL_VERTEX_SHADER);
        this->fragmentShaderID = loadShader(fragmentShaderFile, GL_FRAGMENT_SHADER);

        this->programID = glCreateProgram();
        glAttachShader(this->programID, this->vertexShaderID);
        glAttachShader(this->programID, this->fragmentShaderID);
    }

    void ShaderProgram::postSetup()
    {
        glLinkProgram(this->programID);
        glValidateProgram(this->programID);
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

    unsigned int ShaderProgram::getUniformLocation(const std::string& uniformName)
    {
        return glGetUniformLocation(this->programID, uniformName.c_str());
    }

    void ShaderProgram::loadFloat(unsigned int location, float value)
    {
        glUniform1f(location, value);
    }

    void ShaderProgram::loadVector(unsigned int location, const Vector3& vector)
    {
        glUniform3f(location, vector.x, vector.y, vector.z);
    }

    void ShaderProgram::loadBoolean(unsigned int location, bool value)
    {
        unsigned int toLoad = 0;
        if(value) {
            toLoad = 1;
        }

        glUniform1i(location, toLoad);
    }

    void ShaderProgram::loadMatrix(unsigned int location, const Matrix4& matrix)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
    }

    unsigned int ShaderProgram::loadShader(const std::string& filePath, unsigned int type)
    {
        TankTek::Logger::info("Loading Shader: " + filePath);
        std::ifstream file(filePath);
        if(!file.is_open()) {
            std::stringstream ss;
            ss << "Failed to open file: " << filePath;
            Logger::error(ss.str());
            exit(EXIT_FAILURE);
        }

        TankTek::Logger::info("Reading Shader Source...");
        std::string source;
        std::string line;
        while(std::getline(file, line)) {
            source += line + "\n";
        }

        file.close();

        TankTek::Logger::info("Compiling Shader...");
        unsigned int shaderID = glCreateShader(type);

        const char* src = source.c_str();
        glShaderSource(shaderID, 1, &src, nullptr);
        glCompileShader(shaderID);

        TankTek::Logger::info("Checking Shader Compilation...");
        int success;
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if(!success) {
            char infoLog[512];
            glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
            std::stringstream ss;
            ss << "Failed to compile shader: " << filePath << "\n" << infoLog;
            Logger::error(ss.str());
            exit(EXIT_FAILURE);
        }

        return shaderID;
    }
}