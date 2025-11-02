#ifndef MISC_H
#define MISC_H

#include <string>
#include <vector>

#include "util/util.h"

class Misc final : Util {
public:
    Misc() : Util("Misc", "Miscellaneous utilities") {}

    static std::vector<std::string> split_string(const std::string& string, char delimiter);
};

#endif // MISC_H
