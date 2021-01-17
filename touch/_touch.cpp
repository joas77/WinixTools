#include <iostream>
#include <cxxopts.hpp>

int main(int argc, char** argv)
{
    cxxopts::Options options("touch", " - change file timestamps");

    options.parse_positional("FILE");
    options.positional_help("FILE");

    options.add_options()
        ("a", "change only the access time", cxxopts::value<bool>()->default_value("false"))
        ("c,no-create", "do not create any files", cxxopts::value<bool>()->default_value("false"))
        ("d,date", "parse STRING and use it instead of current time")
        ("h,help", "Print usage")
        ;

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    
    std::string file;
    if (result.count("FILE"))
    {
        file = result["FILE"].as<std::string>();
        std::cout << "file " << file << std::endl;
    }
    return 0;
}

