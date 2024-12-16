#ifndef PRIM_H
#define PRIM_H

#include "structures/EdgesList.h"
#include "structures/IncidenceMatrix.h"
#include "structures/AdjacencyList.h"

class Prim {
    struct MSTVertex{
        bool visited = false;
        int minWeight = -1;
        int parent = -1;
    };
public:
    static EdgeList getMST(IncidenceMatrix* matrix);
    static EdgeList getMST(AdjacencyList* list);
};
#endif
