#include <AppConfigHandler.hpp>
#include <spdlog/spdlog.h>

AppConfigHandler::AppConfigHandler(const std::string &config_file_path) : ConfigHandler(config_file_path)
{
    spdlog::debug("Created application config handler instance");
}



