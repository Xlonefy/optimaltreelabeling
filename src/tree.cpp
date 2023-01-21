#include <iostream>

#include "tree.h"

Tree::Tree(size_t n_vertexes){
    neighbours_.resize(n_vertexes);
}

std::list<Vertex> Tree::getNeighbours(Vertex v) const {
    return neighbours_[v];
}

void Tree::addEdge(Vertex v1, Vertex v2){
    neighbours_[v1].push_back(v2);
    neighbours_[v2].push_back(v1);
}

Vertex Tree::findARoot(Labeling& labeling) const{
    for (auto i = 0ul; i < neighbours_.size(); i++)
        if (labeling.get(i, 'A') == Label::kEmpty) return i;
    return 0ull;
}

void Tree::print(){
    for (size_t i = 0; i < neighbours_.size(); i++){
        std::cout << i + 1 << ": ";
        for (auto j : neighbours_[i]){
            std::cout << j + 1 << " ";
        }
        std::cout << std::endl;
    }
}
