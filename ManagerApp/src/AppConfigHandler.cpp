#include <AppConfigHandler.hpp>
#include <spdlog/spdlog.h>

#include <fstream>

AppConfigResult AppConfigHandler::validateConfigData()
{
    // To be implemented
    return AppConfigResult::SUCCESS;
}

std::string AppConfigHandler::getResultDescription(AppConfigResult result)
{
    switch (result) {
        case AppConfigResult::SUCCESS:
            return "Success";
        case AppConfigResult::FAILED:
            return "Failed";
        default:
            return "Unknown result";
    }
}

AppConfigHandler::AppConfigHandler(const std::string config_file_path) : m_config_file_path(config_file_path)
{
    spdlog::debug("Created application config handler instance");
}

AppConfigResult AppConfigHandler::init()
{
    std::fstream cfg_file(m_config_file_path);

    if(!cfg_file.is_open()) {
        spdlog::error("Cannot open application config file: {}", m_config_file_path);
        return AppConfigResult::FAILED;
    }

    cfg_file >> m_config_data;

    auto result = validateConfigData();
    if (result != AppConfigResult::SUCCESS) {
        spdlog::error("Failed to validate application config {}. \n\tError: {}", m_config_file_path, getResultDescription(result));
        return result;
    }

    return AppConfigResult::SUCCESS;
}

AppConfigResult AppConfigHandler::reloadConfig()
{
    return init();
}
