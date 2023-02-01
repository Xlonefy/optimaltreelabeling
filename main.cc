#include <iostream>
#include "utils.h"

/**
 * Main entry point.
 * 
*/
int main(int argc, char* argv[]) {

    // getting the filename from the command line.
    if (argc < 2) return -1;
    std::string filename(argv[1]); 

    // reading the given input file
    auto [tree, labeling] = readInputFile(filename);

    // calculates the optimal labeling
    auto optimal_cost = labelOptimallyMultiThread(tree, labeling);

    // printing the output to the standard output
    std::cout << optimal_cost << std::endl;

    return 0;
}
