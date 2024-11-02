#include <TankTek/Logger.hpp>

#include <cstdio>
#include <iomanip>
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
    void Logger::info(const std::string& message)
    {
        printf("[INFO]: %s\n", message.c_str());

        if (Logger::logToFile) {
            std::ofstream file;
            file.open(Logger::logFileName, std::ios_base::app);
            file << "[INFO]: " << message << std::endl;
            file.close();
        }

    }

    void Logger::warn(const std::string& message)
    {
        printf("[WARN]: %s\n", message.c_str());

        if (Logger::logToFile) {
            std::ofstream file;
            file.open(Logger::logFileName, std::ios_base::app);
            file << "[WARN]: " << message << std::endl;
            file.close();
        }
    }

    void Logger::error(const std::string& message)
    {
        printf("[ERROR]: %s\n", message.c_str());

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

        std::stringstream oss;
        std::tm timeInfo;
        localtime_s(&timeInfo, &timeT);
        oss << "log_" << std::put_time(&timeInfo, "%Y-%m-%d_%H-%M-%S") << ".log";

        return oss.str();
    }
}