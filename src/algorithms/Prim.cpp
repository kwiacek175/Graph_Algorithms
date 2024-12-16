#include "algorithms/Prim.h"
#include <climits>

EdgeList Prim::getMST(IncidenceMatrix *matrix) {
    int vertNum = (int)matrix->getNumVertices();
    auto* mstVertex = new MSTVertex[vertNum];

    mstVertex[0].minWeight = 0;

    for (int i = 1; i < vertNum; i++) {
        mstVertex[i].minWeight = INT_MAX;
        mstVertex[i].parent = -1;
        mstVertex[i].visited = false;
    }

    for (int k = 0; k < vertNum - 1; k++) {
        int minParentWeight = INT_MAX;
        int minParent = -1;

        for (int i = 0; i < vertNum; i++) {
            if (!mstVertex[i].visited && mstVertex[i].minWeight < minParentWeight) {
                minParentWeight = mstVertex[i].minWeight;
                minParent = i;
            }
        }

        for (int i = 0; i < matrix->getNumEdges(); i++) {
            int tempParWeight = matrix->getMatrix()[minParent][i];
            if (tempParWeight != 0) {
                for (int j = 0; j < vertNum; j++) {
                    if (minParent == j) continue;
                    int tempChildWeight = matrix->getMatrix()[j][i];
                    if (tempChildWeight != 0) {

                        if (!mstVertex[j].visited && tempChildWeight < mstVertex[j].minWeight) {
                            mstVertex[j].minWeight = tempChildWeight;
                            mstVertex[j].parent = minParent;
                        }
                    }
                }
            }
        }
        mstVertex[minParent].visited = true;
    }

    auto* edges = new EdgeList::Edge[vertNum - 1];
    int j = 0;
    for (int i = 0; i < vertNum; i++) {
        if (mstVertex[i].parent != -1) {
            edges[j].start = mstVertex[i].parent;
            edges[j].end = i;
            edges[j].weight = mstVertex[i].minWeight;
            j++;
        }
    }

    delete[] mstVertex;
    return {(unsigned int)vertNum, (unsigned int)(vertNum - 1), edges};
}

EdgeList Prim::getMST(AdjacencyList *list) {
    int vertNum = (int)list->getVertices();
    auto* mstVertex = new MSTVertex[vertNum];

    mstVertex[0].minWeight = 0;

    for (int i = 1; i < vertNum; i++) {
        mstVertex[i].minWeight = INT_MAX;
        mstVertex[i].parent = -1;
        mstVertex[i].visited = false;
    }

    for (int k = 0; k < vertNum - 1; k++) {
        int minParentWeight = INT_MAX;
        int minParent = -1;

        for (int i = 0; i < vertNum; i++) {
            if (!mstVertex[i].visited && mstVertex[i].minWeight < minParentWeight) {
                minParentWeight = mstVertex[i].minWeight;
                minParent = i;
            }
        }

        AdjacencyList::EdgeList edgeList = list->getAdjList()[minParent];
        for (int i = 0; i < edgeList.size; i++) {
            int tempWeight = edgeList.list[i].weight;
            int tempDest = edgeList.list[i].dest;
            if (!mstVertex[tempDest].visited && tempWeight < mstVertex[tempDest].minWeight) {
                mstVertex[tempDest].minWeight = tempWeight;
                mstVertex[tempDest].parent = minParent;
            }
        }
        mstVertex[minParent].visited = true;
    }

    auto* edges = new EdgeList::Edge[vertNum - 1];
    int j = 0;
    for (int i = 0; i < vertNum; i++) {
        if (mstVertex[i].parent != -1) {
            edges[j].start = mstVertex[i].parent;
            edges[j].end = i;
            edges[j].weight = mstVertex[i].minWeight;
            j++;
        }
    }

    delete[] mstVertex;
    return {(unsigned int)vertNum, (unsigned int)(vertNum - 1), edges};
}