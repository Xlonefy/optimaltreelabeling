#ifndef OTL_INCLUDE_LABEL_H_
#define OTL_INCLUDE_LABEL_H_

#include <string>

enum class Label { kNoLetter, kHasLetter, kIndifferent, kEmpty };

int distance(Label l1, Label l2);
bool isDefined(Label label);


#endif // OTL_INCLUDE_LABEL_H_