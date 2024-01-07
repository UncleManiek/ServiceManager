#pragma once

#include <string>
#include <vector>

#include <spdlog/spdlog.h>

enum class ServiceStatus {
    SUCCESS,
    FAILED
};

class ServiceHandler{
    std::vector<std::string> m_apps_names;
    std::vector<std::string> m_apps_paths;

    int runProcessNonBlocking(std::string &process_command);

public:
    ServiceHandler(std::vector<std::string> apps_names, std::vector<std::string> apps_paths);
    ~ServiceHandler();

    ServiceStatus runAllServices();
    ServiceStatus runSingleService(std::string app_name);

    ServiceStatus stopAllServices();
    ServiceStatus stopSingleService(std::string app_name);
};
