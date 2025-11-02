#include "main.h"

#include <iostream>
#include <ostream>

#include "config/impl/config_parser.h"
#include "util/impl/arg_parse.h"
#include "util/impl/logger.h"
#include "util/impl/misc.h"

#include "features/impl/ddos_protection.h"

const std::string task = "Bootstrap";

int main(const int argc, const char** argv) {
    std::cout << license_message << std::endl;

    const auto [verbose, bind] = ArgParse::parse(argc, argv);

    Logger::info("Loading config from ./protect_thing.service.json");
    const ConfigParser::ProtectThingConfig config = ConfigParser::parse_config("protect_thing.service.json");

    const std::vector<std::string> split_address = Misc::split_string(bind, ':');
    const std::string& port_str = split_address.back();
    const auto port = static_cast<short>(std::stoi(port_str));

    if(const int started = DDoSProtection::start_server(port, config); started != 0)
        Logger::error("Unknown error starting server, check above logs for errors!", task);

    return 0;
}
