#ifndef PROTECTION_H
#define PROTECTION_H

#include <string>
#include <utility>

class Protection {
protected:
    std::string name;
    std::string description;

public:
    Protection(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {}

    virtual ~Protection() = default;

    [[nodiscard]] std::string get_name() const { return name; }
    [[nodiscard]] std::string get_description() const { return description; }

    [[nodiscard]] virtual std::string format() const {
        return "Protection { Name: " + name + ", Description: " + description + " }";
    }
};

#endif // PROTECTION_H
