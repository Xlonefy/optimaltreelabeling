#include <iostream>
#include "label.h"

int distance(Label l1, Label l2){
    if(!isDefined(l1) || !isDefined(l2)) return 0;
    return l1 != l2;
}

bool isDefined(Label label){
    return label == Label::kNoLetter || label == Label::kHasLetter;
}

std::ostream& operator<<(std::ostream& os, const Label label){
    switch (label)
    {
    case Label::kNoLetter:
        os << '0';
        break;
    case Label::kHasLetter:
        os << '1';
        break;
    case Label::kIndifferent:
        os << '-';
        break;
    case Label::kEmpty:
        os << ' ';
        break;
    }
    return os;
}