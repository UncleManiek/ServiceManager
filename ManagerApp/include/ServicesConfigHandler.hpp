#pragma once

#include <string>

#include <nlohmann/json.hpp>

enum class ServicesConfigResult {
    SUCCESS,
    FAILED
};

class ServicesConfigHandler
{
private:
    nlohmann::json m_services_data();

    ServicesConfigResult readServicesConfigData();

public:
    ServicesConfigHandler(const std::string &config_path);  
    ServicesConfigResult init();

    
};

