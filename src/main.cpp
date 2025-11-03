#include "main.h"

#include <iostream>
#include <ostream>
#include <string>
#include <filesystem>
#include <thread>
#include <vector>
#include <functional>

#include "config/impl/config_parser.h"
#include "util/impl/arg_parse.h"
#include "util/impl/logger.h"
#include "util/impl/misc.h"

#include "features/impl/ddos_protection.h"

const std::string task = "Bootstrap";

void start_service(const ConfigParser::ProtectThingConfig& config, std::string service_name) {
    std::stringstream string_stream;
    string_stream << std::this_thread::get_id();
    const std::string thread_id = string_stream.str();

    Logger::info("Starting service: " + service_name + " (Thread ID: " + thread_id + ")");

    if(const int started = DDoSProtection::start_server(config, service_name); started != 0)
        Logger::error("Unknown error starting server, check above logs for errors!", task);
}

int main(const int argc, const char** argv) {
    std::cout << license_message << std::endl;

    if(const auto [verbose] = ArgParse::parse(argc, argv); verbose)
        Logger::info("Verbose mode enabled.");

    Logger::info("Loading services...");

    std::vector<std::thread> threads;

    for(const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator("services")) {
        const std::string path = entry.path().string();

        if(!Misc::has_suffix(path, ".service.json"))
            continue;

        const std::string filename = entry.path().filename().string();
        const std::string service_name = filename.substr(0, filename.find(".service.json"));

        const ConfigParser::ProtectThingConfig config = ConfigParser::parse_config(path);

        threads.emplace_back(start_service, std::cref(config), service_name);
    }

    for(std::thread& thread : threads) {
        if(thread.joinable())
            thread.join();
    }

    return 0;
}
