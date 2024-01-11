/**
 * @file main.cpp
 * @author Tapawingo
 * @brief A tool developed for windows taking inspiration from https://github.com/cheat/cheat
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <windows.h>
#include <iostream>
#include <fstream>
#include <filesystem> // Make sure you have the latest MinGW ver. https://www.mingw-w64.org/downloads/#mingw-builds
#include <shellapi.h>

// Include configs
#include "config.h"

#define FLAGLENGTH 32

// Initial setup
void setup() {
    std::cout << "cheat setup" << std::endl
        << "Creating " << sourceDirectory << " directory..." << std::endl;

    std::filesystem::create_directory(sourceDirectory);

    // Add option to download a default repo of cheats
}

void edit(std::filesystem::path path) {
    if (!std::filesystem::exists(path))
        std::ofstream { path };

    ShellExecute(NULL, "open", path.string().c_str(), NULL, NULL, SW_SHOW);
}

void open(std::filesystem::path path) {
    std::ifstream f(path);
    
    if (f.is_open()) {
        std::cout << f.rdbuf() << std::endl;
    } else {
        std::cout << "cheat" << ": Not found in " << sourceDirectory << std::endl;
    }
}

int main(int argc, char* argv[]) {
    std::filesystem::path cheat;
    
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != (char)* "-") {
            cheat = argv[i];
            break;
        }
    }

    if (!std::filesystem::exists(sourceDirectory))
        setup();

    std::filesystem::path path = sourceDirectory / cheat;
    if (sourceDirectory.compare(path) == 0) { // Doesn't actually work as the nullbyte is still appended as a file
        std::cout << "Missing keyword" << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("-e")) {
            edit(path);
            return 0;
        }
    }

    open(path);

    return 0;
}
