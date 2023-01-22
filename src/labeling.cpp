#include <iostream>
#include "labeling.h"
#include "constants.h"


Labeling::Labeling(){
    // labels_.resize(kNLetters);
}

void Labeling::labelVertex(const Vertex& v, std::string label){
    labels_[v] = std::vector(kNLetters, Label::kNoLetter);
    for(auto i = 0ul; i < label.length(); i++)
        labels_[v][label[i] - 'A'] = Label::kHasLetter;
}

Label& Labeling::get(const Vertex &v, char letter){
    if (!labels_.count(v))
        labels_[v] = std::vector(kNLetters, Label::kEmpty);
    return labels_[v][letter - 'A'];
}

void Labeling::print(){
    for (const auto& [vertex, letters] : labels_){
        std::cout << vertex << ": \n";
        for(size_t i = 0; i < kNLetters; i++){
            std::cout << "\t" << static_cast<char>('A' + i) 
                << ": " << letters[i] << std::endl;
        }
    }
}
