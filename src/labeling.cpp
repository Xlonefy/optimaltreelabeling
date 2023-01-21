#include <unordered_map>
#include "labeling.h"


Labeling::Labeling(){
    const char kNLetters = 26;
    for (auto i = 0; i < kNLetters; i++){
        std::unordered_map<Vertex, Label> map;
        labels_[i] = map;
    }
}

void Labeling::labelVertex(const Vertex& v, std::string label){
    // const char kNLetters = 26;
    // for(auto i = 0; i < kNLetters; i++)
    //     labels_[i][v] = Label::kNoLetter;
    // for(auto i = 0ul; i < label.length(); i++)
    //     labels_[label[i] - 'A'][v] = Label::kHasLetter;
}

void Labeling::labelVertex(const Vertex& v){
    // const char kNLetters = 26;
    // for(auto i = 0; i < kNLetters; i++)
    //     labels_[i][v] = Label::kEmpty;
}

const Label& Labeling::get(const Vertex &v, char letter) const {
    return Label::kEmpty;
    // return labels_[letter - 'A'][v];
}
Label & Labeling::get(const Vertex &v, char letter){
    Label l = Label::kEmpty;
    return l;
}
