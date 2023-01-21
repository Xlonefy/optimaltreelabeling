#include <iostream>
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) return -1;
    std::string filename(argv[1]); 
    auto [t, l] = readInputFile(filename);
    auto res = labelOptimally(t, l);
    std::cout << res << std::endl;
    return 0;
}