#include "config/impl/config_parser.h"

#include <cJSON.h>
#include "util/impl/fs.h"
#include "util/impl/logger.h"

ConfigParser::ProtectThingConfig ConfigParser::parse_config(const std::string& path) {
    ProtectThingConfig config;

    const std::string json_string = FS::read_to_string(path);
    cJSON* json = cJSON_Parse(json_string.c_str());

    if(!json) {
        const char* error_ptr = cJSON_GetErrorPtr();
        std::string error_msg = "JSON Parse Error";

        if(error_ptr)
            error_msg += ": " + std::string(error_ptr);

        throw std::runtime_error(error_msg);
    }

    try {
        const cJSON* name = cJSON_GetObjectItemCaseSensitive(json, "name");
        const cJSON* protocol = cJSON_GetObjectItemCaseSensitive(json, "protocol");
        const cJSON* hostname = cJSON_GetObjectItemCaseSensitive(json, "hostname");
        const cJSON* port = cJSON_GetObjectItemCaseSensitive(json, "port");
        const std::string name_str = name->valuestring;
        const std::string protocol_str = protocol->valuestring;
        const std::string hostname_str = hostname->valuestring;
        const auto port_short = static_cast<short>(port->valueint);

        config.name = name_str;
        config.protocol = protocol_str;
        config.hostname = hostname_str;
        config.port = port_short;
    } catch(const std::exception &exception) {
        Logger::error(exception.what(), "ConfigParser");
        cJSON_Delete(json);

        throw;
    }

    cJSON_Delete(json);
    return config;
}

