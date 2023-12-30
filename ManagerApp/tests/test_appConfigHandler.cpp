#include <gtest/gtest.h>
#include <AppConfigHandler.hpp>

#include <fstream>

using json = nlohmann::json;

TEST(AppConfigHandlerTest, ValidateAppsMissing){

    const std::string file_path = "config.json";

    //create testing json file
    json data = { "test", "test123" };
    std::ofstream test_json(file_path);
    if(!test_json.is_open()) {
        FAIL() << "Failed to create stub config.json";
    }

    auto config_handler = std::make_unique<AppConfigHandler>(file_path);
    //config_handler->init();
    EXPECT_EQ(config_handler->validateConfigData(), ConfigResult::FAILED);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}