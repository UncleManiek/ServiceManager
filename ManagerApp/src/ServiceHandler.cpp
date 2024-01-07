#include "ServiceHandler.hpp"
#include <cstdlib>
#include <future>
#include <chrono>

int ServiceHandler::runProcessNonBlocking(std::string &process_command)
{
    pid_t pid = fork();

    if (pid == -1) {
        spdlog::error("Failed when executing fork()");
        return -1;
    } else if (pid == 0) {
        //running process command
        execvp(process_command.c_str(), NULL);

        spdlog::error("Error when running process from commad: {}", process_command);
        return 1;
    } else {
        spdlog::info("Successfully ran process command {}", process_command);
    }

    return 0;
}

ServiceHandler::ServiceHandler(std::vector<std::string> apps_names, std::vector<std::string> apps_paths) : m_apps_names(apps_names), m_apps_paths(apps_paths)
{
    spdlog::info("Initialized ServiceHandler");
}

ServiceHandler::~ServiceHandler()
{
}

ServiceStatus ServiceHandler::runAllServices()
{
    return ServiceStatus();
}

ServiceStatus ServiceHandler::runSingleService(std::string app_name)
{
    return ServiceStatus();
}

ServiceStatus ServiceHandler::stopAllServices()
{
    return ServiceStatus();
}

ServiceStatus ServiceHandler::stopSingleService(std::string app_name)
{
    return ServiceStatus();
}
