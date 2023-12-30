#include FetchContent for pulling external sources
include(FetchContent)

FetchContent_Declare(googletest 
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)


add_executable(ManagerAppTests
    test_appConfigHandler.cpp
    ../src/AppConfigHandler.cpp #shouldnt be like that
    ../src/ConfigHandler.cpp #shouldnt be like that
)

target_include_directories(ManagerAppTests PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(ManagerAppTests
    nlohmann_json::nlohmann_json
    spdlog::spdlog
    
    gtest
    gtest_main
    gmock
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(ManagerAppTests)