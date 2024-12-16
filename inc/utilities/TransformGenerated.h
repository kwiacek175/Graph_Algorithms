#ifndef TRANSFORMGENERATED_H
#define TRANSFORMGENERATED_H

#include "structures/IncidenceMatrix.h"
#include "structures/AdjacencyList.h"
#include "structures/EdgesList.h"

class TransformGenerated {
public:
    static IncidenceMatrix transformToMatrix(EdgeList* wrap);
    static AdjacencyList transformToList(EdgeList* wrap);
};
#endif
