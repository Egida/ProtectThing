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

bool Misc::has_suffix(const std::string& string, const std::string& suffix) {
    return string.size() >= suffix.size() &&
        string.compare(string.size() - suffix.size(), suffix.size(), suffix) == 0;
}

std::string Misc::get_hostname_from_url(const std::string& url) {
    std::string hostname = url;
    const size_t protocol_pos = hostname.find("://");

    if (protocol_pos != std::string::npos)
        hostname = hostname.substr(protocol_pos + 3);

    const size_t path_pos = hostname.find('/');

    if (path_pos != std::string::npos)
        hostname = hostname.substr(0, path_pos);

    const size_t port_pos = hostname.find(':');

    if (port_pos != std::string::npos)
        hostname = hostname.substr(0, port_pos);

    return hostname;
}
