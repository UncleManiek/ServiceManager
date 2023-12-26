#include <AppConfigHandler.hpp>
#include <spdlog/spdlog.h>

AppConfigHandler::AppConfigHandler(const std::string &config_file_path) : ConfigHandler(config_file_path)
{
    spdlog::debug("Created application config handler instance");
}

ConfigResult AppConfigHandler::validateConfigData()
{
    // following steps should be run for perform validation

    //1. validate if apps array exists
    if (!m_config_data.contains("apps")) {
        spdlog::error("App config json doesn't contain 'apps' object in root");
        return ConfigResult::FAILED;
    }

    //2. validate if app object is array object
    if (!m_config_data["apps"].is_array()) {
        spdlog::error("'apps' object is not and json array");
        return ConfigResult::FAILED;
    }

    //3. validate if all elements in apps array contains following obligatory fields: app_name, app_path
    for (const auto &app_obj : m_config_data["apps"]) {
        if (!app_obj.contains("app_name") || !app_obj.contains("app_path")) {
            spdlog::error("One of 'apps' objects doesn't contain 'app_name' or 'app_path' field");
            return ConfigResult::FAILED;
        }
    }

    return ConfigResult::SUCCESS;
}
