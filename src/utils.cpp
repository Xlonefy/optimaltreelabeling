#include <iostream>
#include <fstream>
#include <string>

#include "utils.h"
#include "labeling.h"
#include "tree.h"

std::pair<Tree, Labeling> readInputFile(std::string filename){

    // initializes the stream
    std::ifstream file(filename);

    // checks if the file is open
    if(!file.is_open())
        throw std::invalid_argument("File not found.");
    
    // getting N (number of vertices) and L (number of leafs) from the first line
    int N, L;
    file >> N >> L;

    // initializes a tree and helper vertices
    Tree tree(N);
    Vertex v1, v2;

    // reads the file and store each edge in the tree.
    for(auto i = 0; i < N - 1; i++){
        file >> v1 >> v2;
        tree.addEdge(v1 - 1, v2 - 1);
    }

    // initializes the Labeling
    Labeling labeling(N);

    // helper variables
    Vertex v;
    std::string label;

    // reads the file and label each vertex accordingly
    for(auto i = 0; i < L; i++){
        file >> v >> label;
        if(label == "$") labeling.labelVertex(v - 1, "");
        else labeling.labelVertex(v - 1, label);
    }

    // return the populated Tree and Labeling objects.
    return {tree, labeling};
}