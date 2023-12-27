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
    auto config_handler = std::make_unique<AppConfigHandler>(config_path);
    config_handler->init();

    if (config_handler->validateConfigData() != ConfigResult::SUCCESS){
        spdlog::error("Failed to validate config");
    }

    auto apps_names =  config_handler->getAllAppsName();
    if (!apps_names.empty()){
        for(const auto& name : apps_names){
            spdlog::info("{}", name);
        }
    }

    auto app_path = config_handler->getAppPath("app1");
    spdlog::info("{}", app_path);

    auto app_params = config_handler->getAppParams("app1");
    if (!app_params.empty()){
        for(const auto& param : app_params){
            spdlog::info("{}", param);
        }
    }

    return 0;
}