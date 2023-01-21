#include "tree.h"

Tree::Tree(size_t n_vertexes){
    neighbours_.resize(n_vertexes);
    for(auto i = 0ul; i < n_vertexes; i++){
        std::list<Vertex> l;
        neighbours_[i] = l;
    }
}

std::list<Vertex> Tree::getNeighbours(Vertex v) const {
    return neighbours_[v];
}

void Tree::addEdge(Vertex v1, Vertex v2){
    neighbours_[v1].push_back(v2);
    neighbours_[v2].push_back(v1);
}

Vertex Tree::findARoot(const Labeling& labeling) const{
    for(auto i = 0ul; i < neighbours_.size(); i++)
        if(labeling.get(i, 'a') == Label::kEmpty) return i;
    return 0ull;
}
