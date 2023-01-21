#ifndef OTL_INCLUDE_LABELING_H_
#define OTL_INCLUDE_LABELING_H_

#include "label.h" 
#include "vertex.h" 

class Labeling {
public:
    Label &get(const Vertex &v, char letter);
    const Label &get(const Vertex &v, char letter) const;
private:

};

#endif // OTL_INCLUDE_LABELING_H_