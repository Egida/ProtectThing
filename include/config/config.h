#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <utility>

class Config {
protected:
    std::string name;
    std::string description;

public:
    Config(std::string  name, std::string  description)
        : name(std::move(name)), description(std::move(description)) {}

    virtual ~Config() = default;

    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] std::string get_description() const { return description; }

    [[nodiscard]] virtual std::string format() const {
        return "Config { Name: " + name + ", Description: " + description + " }";
    }
};

#endif // CONFIG_H
