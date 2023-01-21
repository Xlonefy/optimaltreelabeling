#ifndef OTL_INCLUDE_LABELING_H_
#define OTL_INCLUDE_LABELING_H_

#include <unordered_map>
#include <vector>
#include "label.h" 
#include "vertex.h" 

class Labeling {
public:
    Labeling();
    Label &get(const Vertex &v, char letter);
    const Label& get(const Vertex &v, char letter) const;
    void labelVertex(const Vertex& v, std::string label);
    void labelVertex(const Vertex& v);
private:
    std::vector<std::unordered_map<Vertex, Label>> labels_;
};

#endif // OTL_INCLUDE_LABELING_H_