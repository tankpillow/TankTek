#ifndef TT_Logger_HPP_
#define TT_Logger_HPP_

#include <string>

namespace TankTek
{
    class Logger
    {
        private:
            static bool logToFile;
            static std::string logFileName;
        public: // Setup
            static void init(bool logToFile);
        public: // Methods
            static void info(const std::string& message);
            static void warn(const std::string& message);
            static void error(const std::string& message);
        private: // Utils
            static std::string getFileName();
    };
}

#endif