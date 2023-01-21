#ifndef OTL_INCLUDE_UTILS_H_
#define OTL_INCLUDE_UTILS_H_

#include <utility>

#include "tree.h"
#include "labeling.h"

std::pair<Tree, Labeling> readInputFile(std::string filename);
unsigned long long labelOptimally(const Tree& tree, Labeling& labeling);

#endif // OTL_INCLUDE_UTILS_H_