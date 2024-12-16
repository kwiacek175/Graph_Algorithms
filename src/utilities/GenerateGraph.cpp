#include <stdexcept>
#include <random>
#include "utilities/GenerateGraph.h"

EdgeList GenerateGraph::generateEdgeList(unsigned int vertices, unsigned char density) {
    if(density < 25){
        throw std::runtime_error("GenerateGraph: Min density is 25");;
    }
    if(density > 100){
        throw std::runtime_error("GenerateGraph: Max density is 100");;
    }
    unsigned int totalEdges = (vertices * (vertices - 1)) * density / 100;
    unsigned long edgesToGenerate = totalEdges;
    if(edgesToGenerate < vertices) throw std::runtime_error("GenerateGraph: ERROR");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weight(1, 100);

    auto* edges = new EdgeList::Edge[totalEdges];

    int* verticesToVisit = new int[vertices - 1];
    int verticesToVisitSize = (int) vertices - 1;
    for(int i = 0; i < vertices - 1; i++){
        verticesToVisit[i] = i + 1;
    }

    int prevVer= 0;
    for (int i = 0; i < vertices - 1; i++) {
        std::uniform_int_distribution<> vert(0, verticesToVisitSize);
        int tempEnd = verticesToVisit[vert(gen)];
        bool notContinue = true;
        for(int j = 0; j < verticesToVisitSize; j++){
            if(verticesToVisit[j] == tempEnd) {
                notContinue = false;
                break;
            }
        }
        if(notContinue){
            i--;
            continue;
        }

        int offset = 0;
        for(int j = 0; j < verticesToVisitSize - 1; j++){
            if(verticesToVisit[j] == tempEnd) offset = 1;
            verticesToVisit[j] = verticesToVisit[j + offset];
        }
        verticesToVisitSize--;

        edges[i].start = prevVer;
        edges[i].weight = weight(gen);
        prevVer = tempEnd;
        edges[i].end = tempEnd;

        edgesToGenerate--;
    }
    delete[] verticesToVisit;

    std::uniform_int_distribution<> vert(0, (int)vertices - 1);

    for (int i = (int)vertices - 1; i < totalEdges; i++){
        int tempStart = vert(gen);
        int tempEnd;
        do{
            tempEnd = vert(gen);
        } while (tempEnd == tempStart);
        if(isExisting(edges, totalEdges - edgesToGenerate, tempStart, tempEnd)) {
            i--;
            continue;
        }

        edges[i].start = tempStart;
        edges[i].end = tempEnd;
        edges[i].weight = weight(gen);
        edgesToGenerate--;
    }
    return {vertices, totalEdges, edges};
}

bool GenerateGraph::isExisting(EdgeList::Edge *list, unsigned int size, unsigned int start, unsigned int end) {
    for(int i = 0; i < size; i++){
        if(list[i].start == start){
            if(list[i].end == end) return true;
        }
    }
    return false;
}

