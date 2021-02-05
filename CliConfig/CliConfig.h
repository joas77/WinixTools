#pragma once

#include <iostream>
#include <string>
#include <CLI/CLI.hpp>
#include <nlohmann/json.hpp>


namespace CliCfg 
{

	using json = nlohmann::json;

	class CliConfig
	{
	public:

		CliConfig(const std::string& configFile);

		template <typename T>
		T getValue(std::string optName);
	};

}