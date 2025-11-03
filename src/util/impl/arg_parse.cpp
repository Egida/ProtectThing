#include "util/impl/arg_parse.h"

#include <functional>
#include <iostream>
#include <unordered_map>
#include <string>

#include "util/impl/logger.h"
#include "main.h"

Option ArgParse::parse(const int count, const char* args[]) {
    std::unordered_map<std::string, std::function<void(Option&, const std::string&)>> cli_flags = {
        {"--verbose", [](Option& opt, const std::string&) -> void { opt.verbose = true; }},
        {"-v", [](Option& opt, const std::string&) -> void { opt.verbose = true; }},
        {
            "--license-warranty", [](Option&, const std::string&) -> void {
                std::cout << license_warranty << std::endl;
                exit(0);
            }
        },
        {
            "--license-conditions", [](Option&, const std::string&) -> void {
                std::cout << license_conditions << std::endl;
                exit(0);
            }
        },
        {
            "--license-all", [](Option&, const std::string&) -> void {
                std::cout << license_full << std::endl;
                exit(0);
            }
        },
        {
            "--help", [](Option&, const std::string&) -> void {
                std::cout << "Usage: protect_thing [options] <command>\n"
                    << "Options:\n"
                    << "  -v, --verbose    Enable verbose output\n"
                    << "  -b, --bind       Address to bind to\n"
                    << "  --help           Show this help message\n";
                exit(0);
            }
        }
    };

    Option option = {
        .verbose = false,
    };

    for(int i = 1; i < count; ++i) {
        std::string arg = args[i];

        if(arg[0] != '-') {
            continue;
        }

        auto it = cli_flags.find(arg);
        if(it == cli_flags.end()) {
            Logger::error("Unknown Option: " + arg, "Main");
            exit(1);
        }

        if(i + 1 >= count) {
            Logger::error(arg + " requires a value!", "Main");
            exit(1);
        }

        it->second(option, args[++i]);
    }

    return option;
}
