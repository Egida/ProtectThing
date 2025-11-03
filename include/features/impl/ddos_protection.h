#ifndef PROTECTTHING_DDOS_PROTECTION_H
#define PROTECTTHING_DDOS_PROTECTION_H

#include "config/impl/config_parser.h"
#include "features/protection.h"

class DDoSProtection final : Protection {
public:
    DDoSProtection() : Protection("DDoSProtection", "Handles core DDoS protection") {}
    static int start_server(const ConfigParser::ProtectThingConfig& config, const std::string& portal_log_name);

private:
    static void poll_traffic();
};

#endif // PROTECTTHING_DDOS_PROTECTION_H
