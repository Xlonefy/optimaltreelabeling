#include <iostream>
#include <string>
#include <unordered_map>
// #include "label.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "utils.h"

int main() {
    // std::unordered_map<int, std::list<int>> labels_;
    // std::unordered_map<char, Label> map;
    // labels_.find(1);
    // // labels_[1] = map;
    // // labels_[1]['a'] = Label::kHasLetter;
    // std::cout<< labels_ << std::endl;

    readInputFile("test.txt");

    // std::cout << m['b']<< std::endl;

    std::cout << 'B' - 'A'<< std::endl;
    return 0;
}