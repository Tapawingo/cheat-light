#include <iostream>
#include <fstream>
#include <filesystem> // Make sure you have the latest MinGW ver. https://www.mingw-w64.org/downloads/#mingw-builds

// Include configs
#include "config.h"
#include "config.def.h"

void setup() {
    std::cout << "cheat setup" << std::endl
        << "Creating " << sourceDirectory << " directory..." << std::endl;

    std::filesystem::create_directory(sourceDirectory);

    // Add option to download a default repo of cheats
}

int main(int argc, char* argv[]) {
    if (!std::filesystem::exists(sourceDirectory)) {
        setup();
    }
    
    if (argc < 2) {
        std::cout << "No keyword submitted" << std::endl;
        return 1;
    }
    
    std::filesystem::path cheat = argv[1];
    std::filesystem::path path = sourceDirectory / cheat;

    std::ifstream f(path);
    
    if (f.is_open()) {
        std::cout << f.rdbuf() << std::endl;
    } else {
        std::cout << cheat << ": Not found in " << sourceDirectory << std::endl;
        return 1;
    }

    return 0;
}
