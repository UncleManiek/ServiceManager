#include <ConfigHandler.hpp>
#include <spdlog/spdlog.h>

#include <fstream>

ConfigHandler::ConfigHandler(const std::string &config_file) :
    m_config_file_path(config_file) {}

ConfigResult ConfigHandler::init()
{
    std::fstream cfg_file(m_config_file_path);

    if(!cfg_file.is_open()) {
        spdlog::error("Cannot open config file: {}", m_config_file_path);
        return ConfigResult::FAILED;
    }

    cfg_file >> m_config_data;

    auto result = validateConfigData();
    if (result != ConfigResult::SUCCESS) {
        return result;
    }

    return ConfigResult::SUCCESS;
}

ConfigResult ConfigHandler::reloadConfig()
{
    return init();
}

ConfigResult ConfigHandler::validateConfigData()
{
    return ConfigResult::SUCCESS;
}
