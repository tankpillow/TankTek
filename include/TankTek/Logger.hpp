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
            static void info(const char* message);
            static void warn(const char* message);
            static void error(const char* message);
        private: // Utils
            static std::string getFileName();
    };
}

#endif