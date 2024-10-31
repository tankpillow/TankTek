#include <TankTek/Logger.hpp>

#include <stdio.h>
#include <chrono>
#include <fstream>
#include <sstream>

namespace TankTek
{   
    // Static Variables
    //---------------------------------------------------------------------------------
    bool Logger::logToFile = false;
    std::string Logger::logFileName = "";

    // Setup
    //---------------------------------------------------------------------------------
    void Logger::init(bool logToFile)
    {
        Logger::logToFile = logToFile;
        Logger::logFileName = Logger::getFileName();
    }

    // Methods
    //---------------------------------------------------------------------------------
    void Logger::info(const char* message)
    {
        printf("[INFO]: %s\n", message);

        if (Logger::logToFile) {
            std::ofstream file;
            file.open(Logger::logFileName, std::ios_base::app);
            file << "[INFO]: " << message << std::endl;
            file.close();
        }

    }

    void Logger::warn(const char* message)
    {
        printf("[WARN]: %s\n", message);

        if (Logger::logToFile) {
            std::ofstream file;
            file.open(Logger::logFileName, std::ios_base::app);
            file << "[WARN]: " << message << std::endl;
            file.close();
        }
    }

    void Logger::error(const char* message)
    {
        printf("[ERROR]: %s\n", message);

        if (Logger::logToFile) {
            std::ofstream file;
            file.open(Logger::logFileName, std::ios_base::app);
            file << "[ERROR]: " << message << std::endl;
            file.close();
        }
    }

    // Utils
    //---------------------------------------------------------------------------------
    std::string Logger::getFileName()
    {
        auto now = std::chrono::system_clock::now();
        auto timeT = std::chrono::system_clock::to_time_t(now);

        std::tm localTime = *std::localtime(&timeT);

        std::ostringstream oss;
        oss << "log-" << std::put_time(&localTime, "%Y-%m-%d-%H-%M-%S") << ".txt";

        return oss.str();
    }
}