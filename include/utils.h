#ifndef OTL_INCLUDE_UTILS_H_
#define OTL_INCLUDE_UTILS_H_

#include <utility>

#include "tree.h"
#include "labeling.h"

/**
 * Read the input file into Tree and Labeling objects.
 * 
 * @param filename: path to the file to be read from the root directory.
 *      Example "6.in" or any other text extention;
 * @returns: pair of Tree and Labeling objects that encode the labeled tree
 *      for the problem.
 * 
*/
std::pair<Tree, Labeling> readInputFile(std::string filename);

/**
 * Label the given tree with optimal labels.
 * 
 * @param tree: the considered unrooted tree.
 * @param labeling: the given label for that tree. 
 *      Will be modified by the function.
 * 
 * We assume that the tree is well constructed (connected and with no cycles)
 * and that the all the leafs (and only the leafs) are labeled in the input.
 * 
 * Time complexity of the algorithm is of O(n), where 
 * n is the number of vertices on the tree.
 * 
*/
unsigned long long labelOptimally(const Tree& tree, Labeling& labeling);

#endif // OTL_INCLUDE_UTILS_H_