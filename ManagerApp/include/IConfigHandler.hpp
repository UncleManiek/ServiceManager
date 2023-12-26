#pragma once

#include <nlohmann/json.hpp>
#include <string>

enum class ConfigResult {
    SUCCESS,
    FAILED
};

class IConfigHandler
{
public:
    virtual ~IConfigHandler() = default;

    virtual ConfigResult init() = 0;
    virtual ConfigResult reloadConfig() = 0;
    
};

