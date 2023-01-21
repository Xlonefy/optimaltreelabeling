#include "utils.h"

unsigned long long labelOneLetter(const Tree& tree, Labeling& labeling, Vertex root,
                                  Vertex parent, char letter);

unsigned long long labelOptimally(const Tree& tree, Labeling& labeling) {
    const char kNLetters = 26;
    const char kAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    auto root = tree.findARoot(labeling);

    auto total_cost = 0ull;
    for (size_t i = 0; i < kNLetters; i++)
        total_cost += labelOneLetter(tree, labeling, root, root, kAlphabet[i]);

    return total_cost;
}

unsigned long long labelOneLetter(const Tree& tree, Labeling& labeling, Vertex root,
                                  Vertex parent, char letter) {
    
    if (isDefined(labeling.get(root, letter)))
        return 0;
    
    auto cost = 0ull;
    size_t num_has_letter = 0;
    size_t num_no_letter = 0;

    for (auto neighbour : tree.getNeighbours(root)) {
        if (neighbour == parent) continue;

        cost += labelOneLetter(tree, labeling, neighbour, root, letter);
        
        auto neigh_label = labeling.get(neighbour, letter);

        if (neigh_label == Label::kHasLetter) num_has_letter++;
        if (neigh_label == Label::kNoLetter) num_no_letter++;
    }

    labeling.get(root, letter) = (num_no_letter == num_has_letter) ? Label::kIndifferent :
                                 (num_no_letter > num_has_letter) ? Label::kNoLetter : Label::kHasLetter;
    
    return cost + std::min(num_has_letter, num_no_letter);
}

// Vertex findARoot(const Tree& tree, const Labeling& labeling) {
//     Vertex v = 0;
//     while (labeling.get(v, 'a') == Label::kEmpty) v++;
//     return v;
// }