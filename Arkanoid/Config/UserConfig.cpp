#include "UserConfig.h"

UserConfig::UserConfig()
{
    std::ifstream config_File(configPath);
    if (!config_File.is_open()) {
        std::cerr << "Failed to open file: " << configPath << std::endl;
        throw std::runtime_error(R"(Failed to read config file: )" + configPath);
    }

    nlohmann::json json_Data;
    config_File >> json_Data;

    font = json_Data["font"];
    fonts_directory = json_Data["fonts_directory"];
    font_fullPath = json_Data["font_fullPath"];

    std::cout << "Font: " << font << std::endl;
    std::cout << "Fonts Directory: " << fonts_directory << std::endl;
}
