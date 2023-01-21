#include "label.h"

int distance(Label l1, Label l2){
    if(!isDefined(l1) || !isDefined(l2)) return 0;
    return l1 != l2;
}

bool isDefined(Label label){
    return label == Label::kNoLetter || label == Label::kHasLetter;
}