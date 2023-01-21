#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

#include "utils.h"
#include "labeling.h"

std::pair<Tree, Labeling> readInputFile(std::string filename){
    std::ifstream file(filename);

    if(!file.is_open())
        throw std::invalid_argument("File not found.");
    
    // getting N and L from the first line
    int N, L;
    file >> N >> L;

    Tree tree(N);
    Vertex v1, v2;
    for(auto i = 0; i < N - 1; i++){
        file >> v1 >> v2;
        tree.addEdge(v1 - 1, v2 - 1);
    }

    Vertex v;
    Labeling labeling;
    std::string label;
    for(auto i = 0; i < L; i++){
        file >> v >> label;
        if(label == "$") labeling.labelVertex(v - 1, "");
        else labeling.labelVertex(v - 1, label);
    }

    return {tree, labeling};
}