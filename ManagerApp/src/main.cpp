#include <fstream>
#include <string>

#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

//temporary set path
const std::string config_path = "/etc/ServiceManagerConfig.json";

using json = nlohmann::json;

int main()
{
    spdlog::info("Service Manager App started");

    /*Reading app configuration*/
    std::ifstream config_file(config_path);

    if(!config_file.is_open()){
        spdlog::error("Cannot open configuration file:" + config_path +". Make sure file exists...");
        return 1;
    }

    nlohmann::json config_data;
    config_file >> config_data;

    if(config_data.is_null()){
        spdlog::error("Error during reading configuration file: configuration is empty");
        return 2;
    }

    /*Print config data for checking purpose*/
    spdlog::info("{}", config_data.dump(4));

    return 0;
}