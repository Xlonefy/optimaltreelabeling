#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

#include "utils.h"
#include "labeling.h"

std::pair<Tree, Labeling> readInputFile(std::string filename){
    std::ifstream file(filename);
    std::string line, label;
    int delimiter;
    int N, L;
    Vertex v, v1, v2;
    std::unordered_set<Vertex> vertexes;

    if(!file.is_open())
        throw std::invalid_argument("File not found.");
    
    // getting N and L from the first line
    std::getline(file, line);
    delimiter = line.find(" ");
    N = stoi(line.substr(0, delimiter));
    L = stoi(line.substr(delimiter + 1, line.length() - 1));


    Tree tree(N);
    for(auto i = 0; i < N - 1; i++){
        std::getline(file, line);
        delimiter = line.find(" ");
        v1 = stoi(line.substr(0, delimiter));
        v2 = stoi(line.substr(delimiter + 1, line.length() - 1));
        tree.addEdge(v1, v2);
        vertexes.insert(v1);
        vertexes.insert(v2);
    }

    Labeling labeling;
    for(auto i = 0; i < L; i++){
        std::getline(file, line);
        delimiter = line.find(" ");
        v = stoi(line.substr(0, delimiter));
        label = line.substr(delimiter + 1, line.length() - 1);

        vertexes.erase(v);
        if(label == "$") labeling.labelVertex(v, "");
        else labeling.labelVertex(v, label);
    }

    std::pair<Tree, Labeling> p (tree, labeling);
    return p;
}