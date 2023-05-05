#pragma once

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

class UserConfig
{
public:
	UserConfig();
	const std::string configPath = "Config\\config.json";

	std::string font;
	std::string fonts_directory;
	std::string font_fullPath;
};

