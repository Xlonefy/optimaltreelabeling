#include <thread>
#include "utils.h"
#include "constants.h"

void labellingWorker(const Tree &tree, Labeling &labeling, Vertex root,
                     char letter, int &cost);

unsigned long long labelOptimallyMultiThread(const Tree &tree, Labeling &labeling)
{
    // Entrypoint for the algorithm.

    // Finds any possible root for the tree.
    auto root = tree.findARoot(labeling);

    // initializes the total cost as zero
    auto total_cost = 0ull;

    // initializing threads
    std::thread threads[kNLetters];
    for (size_t i = 0; i < kNLetters; i++)
        threads[i] = std::thread(labellingWorker, tree, labeling, root, kAlphabet[i], total_cost);
    for (size_t i = 0; i < kNLetters; i++)
        threads[i].join();

    // returns the total cost of the run
    return total_cost;
}

void labellingWorker(const Tree &tree, Labeling &labeling, Vertex root, char letter, int &cost)
{
    cost += labelOneLetter(tree, labeling, root, root, letter);
}