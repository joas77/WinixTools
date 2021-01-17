#include <iostream>
#include <string>

#include <Poco/File.h>
#include <CLI/CLI.hpp>
#include <Poco/Timestamp.h>


#define VERSION "0.0.1"

int main(int argc, char** argv) {

    CLI::App app("touch - change filestamps");
    // add version output
    app.set_version_flag("--version", std::string(VERSION));

    std::string filePath;
    CLI::Option* optFile = app.add_option("FILE", filePath);

    bool flagAccessTime;
    CLI::Option* opt = app.add_flag("-a", flagAccessTime, "change only the access time");
    
    
    bool flagDoNotCreate;
    CLI::Option* copt = app.add_flag("-c,--no-create", flagDoNotCreate, "do not create any files");

    bool flagM;
    app.add_flag("-m", flagM, "change only the modification time");

    std::string referenceFile;
    app.add_option("-r,--reference", referenceFile, "use this file's times instead of current time");


    CLI11_PARSE(app, argc, argv);


    Poco::File file = Poco::File(filePath);
    
    if (file.exists())
    {
        Poco::Timestamp now;
        file.setLastModified(now);
    }
    else
    {
        file.createFile();
    }


    return 0;
}