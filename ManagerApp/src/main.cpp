#include <iostream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>


using json = nlohmann::json;

int main()
{
    std::cout << "Starting service manager" << std::endl;
    spdlog::info("Test spdlog");

    json empty_array_explicit = json::array();
    return 0;
}