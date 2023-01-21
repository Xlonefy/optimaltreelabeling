#ifndef OTL_INCLUDE_TREE_H_
#define OTL_INCLUDE_TREE_H_

#include <cstddef>
#include <vector>
#include <list>

#include "vertex.h"
#include "labeling.h"

/**
 * Tree class
 * 
 * Represents a undirected tree using an adjacency list.
 * 
*/
class Tree {
public:
    /**
     * Contruct a new tree.
     * 
     * @param n_vertexes: number of vertexes on the tree.
     * 
     * Initializes the tree with the indicated number of vertices 
     * in crescent order and with no edges.
     * 
     * Space complexity of O(n_vertexes).
    */
    Tree(size_t n_vertexes);

    /**
     * Get the neighbours of a vertex.
     * 
     * @param v: query vertex.
     * 
     * @returns a list of vertices representing the neighbours of
     *      the query vertex.
     * 
     * Operation of time complexity O(1)
    */
    std::list<Vertex> getNeighbours(Vertex v) const;

    /**
     * Add an edge between two vertices
     * 
     * @param v1: one of the vertexes of the edge
     * @param v2: the other vertex of the edge
     * 
     * @return void
     * 
     * Constructs an undirected edge between v1 and v2.
     * 
     * Operation of time complexity O(1)
    */
    void addEdge(Vertex v1, Vertex v2);

    /**
     * Find a root for the tree.
     * 
     * @param labeling: a label mapping for the vertices of this tree.
     * 
     * @return: a possible root vertex (not a leaf of the tree).
     * 
     * Given that the constructed tree is unrooted, the choice for a root in this function
     * is not unique. 
     * 
     * Operation of time complexity of O(n_vertexes) in the worst case.
     * 
    */
    Vertex findARoot(Labeling& labeling) const;

    /**
     * Print the trees adjacency list
    */
    void print();

private:
    std::vector<std::list<Vertex>> neighbours_;
};

#endif // OTL_INCLUDE_TREE_H_