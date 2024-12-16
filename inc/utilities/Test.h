#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "structures/IncidenceMatrix.h"
#include "structures/AdjacencyList.h"
#include "utilities/GenerateGraph.h"
#include "utilities/TransformGenerated.h"

class Test {
public:
    void startTests();
private:
    IncidenceMatrix* matrix;
    AdjacencyList* list;
    GenerateGraph generator;
    TransformGenerated transformer;
    long long calculateTime(int algorithm);
    static void saveToCsvFile(std::string fileName, long long time , int vertexNum,float density);
    static void saveToCsvFile(std::string fileName, std::string message);
    void typeOfDataMessage(std::string message);
};
#endif
