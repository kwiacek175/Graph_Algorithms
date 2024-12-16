#ifndef GENERATEGRAPH_H
#define GENERATEGRAPH_H

#include "structures/EdgesList.h"

class GenerateGraph {
    static bool isExisting(EdgeList::Edge* list, unsigned int size, unsigned int start, unsigned int end);
public:
    static EdgeList generateEdgeList(unsigned int vertices, unsigned char density);
};
#endif
