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
    //2. validate if all elements in apps array contains following obligatory fields: app_name, app_path
    //3. validate if in particular app params fields are in proper order and params nums are fine
    return ConfigResult::SUCCESS;
}
