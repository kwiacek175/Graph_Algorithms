#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "structures/IncidenceMatrix.h"
#include "structures/EdgesList.h"
#include "structures/AdjacencyList.h"

class Dijkstra {
    struct SPTVertex{
        bool visited = false;
        int minWeight = -1;
        int parent = -1;
    };
public:
    static int totalCost;
    static SPTVertex* vertex;
    static EdgeList getSPT(IncidenceMatrix* matrix, int start);
    static EdgeList getSPT(AdjacencyList* list, int start);
    static void printPath(const EdgeList& edgesWrap, int start, int end);
    static int* getPath(int start, int end);
};

#endif
