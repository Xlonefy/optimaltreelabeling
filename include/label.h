#ifndef OTL_INCLUDE_LABEL_H_
#define OTL_INCLUDE_LABEL_H_

#include <string>

/**
 * Represents the different kinds of labels a vertex can have 
 * regarding a letter.
*/
enum class Label { kNoLetter, kHasLetter, kIndifferent, kEmpty };

/**
 * Calculates the Hamming distance between two labels. 
*/
int distance(Label l1, Label l2);

/**
 * Check if a label is well defined.
 * 
 * A label is considered well defined if it either has or not the letter.
 * 
 * Indifferent and Empty labels are not well defined.
*/
bool isDefined(Label label);

/**
 * Operator overcharge to be able to print labels.
*/
std::ostream& operator<<(std::ostream& os, const Label label);

#endif // OTL_INCLUDE_LABEL_H_