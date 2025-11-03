#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include "config/config.h"

class ConfigParser final : Config {
public:
    ConfigParser() : Config("ConfigParser", "Parse the main config") {};

    struct ProtectThingConfig {
        std::string name = "default";
        std::string protocol = "http";
        std::string hostname = "localhost";
        std::string portal_bind = "127.0.0.1:9595";
        short port = 9595;

        [[nodiscard]] std::string format() const {
            return "Config { Name: " + name +
                   ", Protocol: " + protocol +
                   ", Hostname: " + hostname +
                   ", Portal Bind: " + portal_bind +
                   ", Port: " + std::to_string(port) + " }";
        }

        [[nodiscard]] std::string format_url() const {
            return protocol + "://" + hostname + ":" + std::to_string(port) + "/" + name;
        }
    };

    static ProtectThingConfig parse_config(const std::string& path);
};

#endif // CONFIG_PARSER_H
