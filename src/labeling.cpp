#include <algorithm>
#include <iostream>
#include "labeling.h"
#include "constants.h"


Labeling::Labeling(size_t n_vertices) : n_vertices_(n_vertices){
    for (auto &letter_labels : labels_)
        letter_labels = std::vector<Label>(n_vertices, Label::kEmpty);
}

void Labeling::labelVertex(const Vertex& v, std::string label){
    std::for_each(kAlphabet, kAlphabet + kNLetters, [&](char c) {
        get(v, c) = Label::kNoLetter;
    });

    for (char c : label)
        get(v, c) = Label::kHasLetter;
}

Label& Labeling::get(const Vertex &v, char letter){
    return labels_[letter - 'A'][v];
}

void Labeling::print(){
    for (size_t i = 0; i < n_vertices_; i++) {
        std::cout << "Vertex " << i << ": \"";

        if (get(i, 'A') == Label::kEmpty)
            std::cout << "e";

        std::for_each(kAlphabet, kAlphabet + kNLetters, [&](char c) {
            switch (labels_[c - 'A'][i]) {
            case Label::kEmpty:
                // std::cout << "[" << c << "]";
                break;
            case Label::kNoLetter:
                break;
            case Label::kHasLetter:
                std::cout << c;
                break;
            case Label::kIndifferent:
                std::cout << "(" << c << ")";
                break;
            default:
                break;
            }
        });

        std::cout << "\"\n";
    }
}
