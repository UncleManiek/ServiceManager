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
    if (!m_config_data.contains("apps")) {
        spdlog::error("App config json doesn't contain 'apps' object in root");
        return ConfigResult::FAILED;
    }

    //2. validate if app object is array object
    if (!m_config_data["apps"].is_array()) {
        spdlog::error("'apps' object is not and json array");
        return ConfigResult::FAILED;
    }

    //3. validate if all elements in apps array contains following obligatory fields: app_name, app_path
    for (const auto &app_obj : m_config_data["apps"]) {
        if (!app_obj.contains("app_name") || !app_obj.contains("app_path")) {
            spdlog::error("One of 'apps' objects doesn't contain 'app_name' or 'app_path' field");
            return ConfigResult::FAILED;
        }
    }

    //4. validate if all apps names are unuque

    return ConfigResult::SUCCESS;
}

const std::vector<std::string_view> AppConfigHandler::getAllAppsName() const
{
    std::vector<std::string_view> result{};

    for (const auto &app_obj : m_config_data["apps"]) {
        result.push_back(app_obj["app_name"].get<std::string_view>());
    }

    return result;
}

const std::string_view AppConfigHandler::getAppPath(const std::string_view &app_name) const
{
    std::string_view result;

    for (const auto &app_obj : m_config_data["apps"]) {
        if (app_obj["app_name"].get<std::string_view>() == app_name) {
            result = app_obj["app_path"].get<std::string_view>();
            break;
        }
    }

    return result;
}

const std::vector<std::string_view> AppConfigHandler::getAppParams(const std::string_view &app_name) const
{
    std::vector<std::string_view> result{};
    std::size_t params_count{0};

    for (const auto &app_obj : m_config_data["apps"]) {
        if (app_obj["app_name"].get<std::string_view>() == app_name) {
            // check how many params does app have
            for (const auto& field : app_obj.items()) {
                if (field.key().find("param") == 0) {
                    params_count++;
                }
            }

            // iterate over all counted params
            for (std::size_t i = 1; i <= params_count; i++) {
                result.push_back(app_obj["param" + std::to_string(i)].get<std::string_view>());
            }

            break;
        }
    }

    return result;
}
