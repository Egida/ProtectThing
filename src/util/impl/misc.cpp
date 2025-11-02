#include "util/impl/misc.h"

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> Misc::split_string(const std::string& string, const char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream stringstream(string);

    while(std::getline(stringstream, token, delimiter))
        tokens.push_back(token);

    return tokens;
}
