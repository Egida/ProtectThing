#ifndef UTIL_H
#define UTIL_H

#include <string>

class Util {
protected:
    std::string name;
    std::string description;

public:
    Util(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}

    virtual ~Util() = default;

    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] std::string get_description() const { return description; }

    [[nodiscard]] virtual std::string format() const {
        return "Util { Name: " + name + ", Description: " + description + " }";
    }
};

#endif // UTIL_H