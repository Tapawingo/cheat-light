#include <iostream>
#include <fstream>
#include <string>
#include "config.def.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "No keyword submitted" << std::endl;
        return 1;
    };

    std::ifstream f(argv[1]);
    
    if (f.is_open())
        std::cout << f.rdbuf() << std::endl;

    return 0;
}
