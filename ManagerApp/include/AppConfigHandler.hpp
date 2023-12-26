#pragma once
#include <nlohmann/json.hpp>

#include <utility>
#include <ConfigHandler.hpp>

class AppConfigHandler : public ConfigHandler
{
public:
    AppConfigHandler(const std::string& config_file_path);
};