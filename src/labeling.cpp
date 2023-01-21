#include <unordered_map>
#include <iostream>
#include "labeling.h"


Labeling::Labeling(){
    const char kNLetters = 26;
    labels_.resize(kNLetters);
}

void Labeling::labelVertex(const Vertex& v, std::string label){
    const char kNLetters = 26;
    for(auto i = 0; i < kNLetters; i++)
        labels_[i][v] = Label::kNoLetter;
    for(auto i = 0ul; i < label.length(); i++)
        labels_[label[i] - 'A'][v] = Label::kHasLetter;
}

Label& Labeling::get(const Vertex &v, char letter){
    if (!labels_[letter - 'A'].count(v)) 
        labels_[letter - 'A'][v] = Label::kEmpty;
    return labels_[letter - 'A'][v];
}

void Labeling::print(){
    for(size_t i = 0; i < labels_.size(); i++){
        std::cout << static_cast<char>('A' + i) << std::endl;
        for(const auto& [key, value] : labels_[i]){
            std::cout << "\t" << key + 1 << ": " << value << std::endl;
        }
    }
}
