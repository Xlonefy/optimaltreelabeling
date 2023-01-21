#ifndef OTL_INCLUDE_LABELING_H_
#define OTL_INCLUDE_LABELING_H_

#include <map>
#include <vector>
#include "label.h" 
#include "vertex.h" 

/**
 * Labeling class that stores and operates on the labels on a set of vertices.
 * 
 * Labels can be any unordered combination of upper case letters of the alphabet.
 * 
 * Space complexity of the Labeling is O(n), where n is the number of
 * vertices the Labeling covers.
 * 
*/
class Labeling {
public:
    /**
     * Construct an empty labelling.
    */
    Labeling();

    /**
     * Get the label for a vertex and a letter
     * 
     * @param v: the query vertex
     * @param letter: the query letter
     * @return the Label for that letter in that vertex
     * 
     * Operation done in O(1) time complexity.
    */
    Label &get(const Vertex &v, char letter);

    /**
     * Fully label a vertex.
     * @param v: the vertex to be labeled
     * @param label: string representing all the labels that vertex
     *      needs to have. Example: "ADBGJ".
     * 
     * @return void.
     * 
     * Operation done in O(1) time complexity.
     * 
    */
    void labelVertex(const Vertex& v, std::string label);

    /**
     * Print the labeling schema.
    */
    void print();

private:
    std::vector<std::map<Vertex, Label>> labels_;
};

#endif // OTL_INCLUDE_LABELING_H_