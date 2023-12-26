#include <fstream>
#include <string>
#include <memory>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include <AppConfigHandler.hpp>
#include <IConfigHandler.hpp>

//temporary set path
const std::string config_path = "/etc/ServiceManagerConfig.json";

using json = nlohmann::json;

int main()
{
    spdlog::info("Service Manager App started");

    //IConfigHandler *config_handler = new AppConfigHandler(config_path);
    std::unique_ptr<IConfigHandler> config_handler = std::make_unique<AppConfigHandler>(config_path);
    config_handler->init();

    return 0;
}