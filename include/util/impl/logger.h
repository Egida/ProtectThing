#ifndef LOGGER_H
#define LOGGER_H

#include <string>

struct Colors {
    std::string purple = "\033[35m";
    std::string red = "\033[31m";
    std::string yellow = "\033[33m";
    std::string gray = "\033[90m";
    std::string reset = "\033[0m";
};

class Logger {
public:
    static void info(const std::string& message);
    static void info(const std::string& message, const std::string& task);
    static void error(const std::string& message, const std::string& task);
    static void warning(const std::string& message, const std::string& task);
};

#endif // LOGGER_H
