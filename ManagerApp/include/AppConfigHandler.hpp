#pragma once
#include <nlohmann/json.hpp>

#include <utility>
#include <vector>
#include <string_view>

#include <ConfigHandler.hpp>

class AppConfigHandler : public ConfigHandler
{
public:
    /**
     * @brief Constructor
     */
    AppConfigHandler(const std::string& config_file_path);

    /**
     * @brief Overwritten implementation of validation json data. Data is validated right after reading.
    */
    ConfigResult validateConfigData();

    /**
     * @brief Function for getting all apps names from json data
     * @return string_view vector of apps name
    */
    const std::vector<std::string_view> getAllAppsName() const;

    /**
     * @brief Function for getting particular app path.
     * @param app_name - reference for application name - if invalid function returns empty string
     * @return string_view with application path - if argument is invalid - it returns empty string.
    */
    const std::string_view getAppPath(const std::string_view &app_name) const;

    /**
     * @brief Function for getting all params for specific app
     * @param app_name reference to string_view object with application name in json data
     * @return function returns srtring_view vector wit all app parameter
    */
    const std::vector<std::string_view> getAppParams(const std::string_view &app_name) const;
};