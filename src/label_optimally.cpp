#include <iostream>
#include "utils.h"
#include "constants.h"

unsigned long long labelOneLetter(const Tree& tree, Labeling& labeling, Vertex root,
                                  Vertex parent, char letter);

unsigned long long labelOptimally(const Tree& tree, Labeling& labeling) {
    // Entrypoint for the algorithm.

    // Finds any possible root for the tree.
    auto root = tree.findARoot(labeling);

    // initializes the total cost as zero
    auto total_cost = 0ull;

    // runs the subroutine for every possible letter, finding the optimal label for
    // each letter and summing up their costs.
    // Modifies the labeling so that the optimal labeling found is represented.
    for (size_t i = 0; i < kNLetters; i++)
        total_cost += labelOneLetter(tree, labeling, root, root, kAlphabet[i]);

    // returns the total cost of the run
    return total_cost;
}

/**
 * Find the optimal labeling for one letter.
 * 
 * Helper subroutine that finds the optimal labelling for one letter
 * using a greedy algorithm recursive call;
*/
unsigned long long labelOneLetter(const Tree& tree, Labeling& labeling, Vertex root,
                                  Vertex parent, char letter) {
    
    // Base case: encountering a leaf (that is already labeled).
    if (isDefined(labeling.get(root, letter)))
        return 0;
    
    // initializing cost for this sub-tree
    auto cost = 0ull;

    // initializing the counts for the number of children that have or have not
    // the given letter.
    size_t num_has_letter = 0;
    size_t num_no_letter = 0;

    // loops through all the child vertices
    for (auto neighbour : tree.getNeighbours(root)) {
        if (neighbour == parent) continue;

        // recursivelly calculates the cost for the childs subtree.
        // modifies the label of this neighbour to the optimal one.
        cost += labelOneLetter(tree, labeling, neighbour, root, letter);
        
        // getting the optimal neighbour label
        auto neigh_label = labeling.get(neighbour, letter);

        // increase the counters
        if (neigh_label == Label::kHasLetter) num_has_letter++;
        if (neigh_label == Label::kNoLetter) num_no_letter++;
    }

    // Defining the label for the subtree root depending on its neighbours labels
    labeling.get(root, letter) = (num_no_letter == num_has_letter) ? Label::kIndifferent :
                                 (num_no_letter > num_has_letter) ? Label::kNoLetter : Label::kHasLetter;
    
    // returns the total cost for the subtrees plus the cost associated
    // to the root labeling.
    return cost + std::min(num_has_letter, num_no_letter);
}
