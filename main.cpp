#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include "config.def.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No keyword submitted" << std::endl;
        return 1;
    }
    
    std::string cheatName = argv[1];
    // std::filesystem::path cheatFile = cheatName + ".txt";
    std::string cheatFile = cheatName + ".txt";
    // std::filesystem::path cheatSrc = srcDir / cheatFile;
    std::string cheatPath = srcDir + "/" + cheatFile;

    std::ifstream f(cheatFile);
    
    if (f.is_open()) {
        std::cout << f.rdbuf() << std::endl;
    } else {
        std::cout << cheatFile << ": Not found in " << srcDir << std::endl;
        return 1;
    }

    return 0;
}
