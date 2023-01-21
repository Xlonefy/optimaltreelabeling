#ifndef OTL_INCLUDE_TREE_H_
#define OTL_INCLUDE_TREE_H_

#include <cstddef>
#include <vector>
#include <list>

#include "vertex.h"
#include "labeling.h"

class Tree {
public:
    Tree(size_t n_vertexes);

    std::list<Vertex> getNeighbours(Vertex v) const;

    void addEdge(Vertex v1, Vertex v2);

    Vertex findARoot(Labeling& labeling) const;

    void print();

private:
    std::vector<std::list<Vertex>> neighbours_;
};

#endif // OTL_INCLUDE_TREE_H_