#ifndef MISC_H
#define MISC_H

#include <string>
#include <vector>

#include "util/util.h"

class Misc final : Util {
public:
    Misc() : Util("Misc", "Miscellaneous utilities") {}

    static std::vector<std::string> split_string(const std::string& string, char delimiter);
    static bool has_suffix(const std::string& string, const std::string& suffix);
    static std::string get_hostname_from_url(const std::string& url);
};

#endif // MISC_H
