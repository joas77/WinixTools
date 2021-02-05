// CliConfig.cpp : Defines the functions for the static library.
//

#include "CliConfig.h"

namespace CliCfg {

	CliConfig::CliConfig(const std::string& configFile)
	{
	}

	template<typename T>
	T getValue(std::string optName)
	{
		return T();
	}
}