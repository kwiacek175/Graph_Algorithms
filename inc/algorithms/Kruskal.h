#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "structures/EdgesList.h"
#include "structures/IncidenceMatrix.h"
#include "structures/AdjacencyList.h"

class Kruskal {

    struct MSTVertex{
        int color;
    };
public:
    static EdgeList getMST(IncidenceMatrix* matrix);
    static EdgeList getMST(AdjacencyList* list);
};
#endif
