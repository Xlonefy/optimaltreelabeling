#include <iostream>
#include "labeling.h"
#include "constants.h"


Labeling::Labeling(){
    // labels_.resize(kNLetters);
}

void Labeling::labelVertex(const Vertex& v, std::string label){
    // for(auto i = 0; i < kNLetters; i++)
    //     labels_[i][v] = Label::kNoLetter;
    // for(auto i = 0ul; i < label.length(); i++)
    //     labels_[label[i] - 'A'][v] = Label::kHasLetter;

    labels_[v] = std::vector(kNLetters, Label::kNoLetter);
    for(auto i = 0ul; i < label.length(); i++)
        labels_[v][label[i] - 'A'] = Label::kHasLetter;
}

Label& Labeling::get(const Vertex &v, char letter){
    // if (!labels_[letter - 'A'].count(v)) 
    //     labels_[letter - 'A'][v] = Label::kEmpty;
    // return labels_[letter - 'A'][v];

    if (!labels_.count(v))
        labels_[v] = std::vector(kNLetters, Label::kEmpty);
    return labels_[v][letter - 'A'];
}

void Labeling::print(){
    // for(size_t i = 0; i < labels_.size(); i++){
    //     std::cout << static_cast<char>('A' + i) << std::endl;
    //     for(const auto& [key, value] : labels_[i]){
    //         std::cout << "\t" << key + 1 << ": " << value << std::endl;
    //     }
    // }

    for (const auto& [vertex, letters] : labels_){
        std::cout << vertex << ": \n";
        for(size_t i = 0; i < kNLetters; i++){
            std::cout << "\t" << static_cast<char>('A' + i) 
                << ": " << letters[i] << std::endl;
        }
    }
}
