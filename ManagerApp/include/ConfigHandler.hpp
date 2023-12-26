#pragma once

#include <IConfigHandler.hpp>
#include <string>

class ConfigHandler : public IConfigHandler
{
protected:
    virtual ConfigResult validateConfigData();

    nlohmann::json m_config_data;
    std::string m_config_file_path;

public:
    ConfigHandler(const std::string &config_file);
    virtual ~ConfigHandler() = default;

    virtual ConfigResult init();
    virtual ConfigResult reloadConfig();
};

