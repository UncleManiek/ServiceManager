set(APP_NAME ServiceManager)

#include FetchContent for pulling external sources
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(spdlog URL https://github.com/gabime/spdlog/archive/refs/tags/v1.12.0.tar.gz)
FetchContent_MakeAvailable(spdlog)

include_directories(
    include
)

add_executable(${APP_NAME}
    src/main.cpp)

target_link_libraries(${APP_NAME} PRIVATE nlohmann_json::nlohmann_json
                                          spdlog::spdlog)