#pragma once
#include <nlohmann/json.hpp>

#include <utility>

enum class AppConfigResult {
    SUCCESS,
    FAILED
};

class AppConfigHandler
{
private:
    nlohmann::json m_config_data;   // Config data read from file
    std::string m_config_file_path;

    AppConfigResult validateConfigData();
    std::string getResultDescription(AppConfigResult result);

public:
    AppConfigHandler(const std::string config_file_path);

    AppConfigResult init();
    AppConfigResult reloadConfig();

    template<typename T>
    T getConfigValue(const std::string &field_name);
};

template <typename T>
inline T AppConfigHandler::getConfigValue(const std::string &field_name)
{
    //to be refactored to be more robust
    return m_config_data[field_name].get<T>();
}
