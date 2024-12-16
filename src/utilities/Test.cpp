#include <fstream>
#include <chrono>
#include "utilities/Test.h"
#include "structures/EdgesList.h"
#include "algorithms/Prim.h"
#include "algorithms/Kruskal.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BellmanFord.h"

void Test::startTests() {

    float density[] = {99};
    int vertex[] = {20,40,80,100,140,180,200};
    std::string format ="vertex, density[%], time[us]";
    typeOfDataMessage(format);

    for(float d : density){
        for(int v : vertex){

            long long timePrimList=0;
            long long timePrimMatrix=0;
            long long timeKruskalList=0;
            long long timeKruskalMatrix=0;
            long long timeDijkstralList=0;
            long long timeDijkstraMatrix=0;
            long long timeFordBellmanlList=0;
            long long timeFordBellmanMatrix=0;

            for(int i=0;i<5;i++){
                EdgeList edgeWrap = generator.generateEdgeList(v, d);
                matrix = new IncidenceMatrix(transformer.transformToMatrix(&edgeWrap));
                list = new AdjacencyList(transformer.transformToList(&edgeWrap));

                timePrimMatrix += calculateTime(1);
                timePrimList += calculateTime(2);
                timeKruskalMatrix += calculateTime(3);
                timeKruskalList += calculateTime(4);
                timeDijkstraMatrix += calculateTime(5);
                timeDijkstralList += calculateTime(6);
                timeFordBellmanMatrix+= calculateTime(7);
                timeFordBellmanlList += calculateTime(8);
            }

            saveToCsvFile("primList.csv",timePrimList,v,d);
            saveToCsvFile("primMatrix.csv",timePrimMatrix,v,d);
            saveToCsvFile("kruskalList.csv",timeKruskalList,v,d);
            saveToCsvFile("kruskalMatrix.csv",timeKruskalMatrix,v,d);
            saveToCsvFile("dijkstraList.csv",timeDijkstralList,v,d);
            saveToCsvFile("dijkstraMatrix.csv",timeDijkstraMatrix,v,d);
            saveToCsvFile("fordBellmanList.csv",timeFordBellmanlList,v,d);
            saveToCsvFile("fordBellmanMatrix.csv",timeFordBellmanMatrix,v,d);
        }
    }
}


void Test::saveToCsvFile(std::string fileName, long long time , int vertexNum,float density){
    std::ofstream file(fileName,std::ios::out | std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
        return;
    }
    double time2;
    time2 = static_cast<double>(time)/5;
    file << vertexNum << ","<<density<<","<<time2<<std::endl;
    file.close();
}

void Test::saveToCsvFile(std::string fileName, std::string message){
    std::ofstream file(fileName,std::ios::out | std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << fileName << " do zapisu!" << std::endl;
        return;
    }
    file<<message<<std::endl;
    file.close();
}

void Test::typeOfDataMessage(std::string message){
    std::cout<<"utworzono plik"<<std::endl;
    saveToCsvFile("primList.csv",message);
    saveToCsvFile("primMatrix.csv",message);
    saveToCsvFile("kruskalList.csv",message);
    saveToCsvFile("kruskalMatrix.csv",message);
    saveToCsvFile("dijkstraList.csv",message);
    saveToCsvFile("dijkstraMatrix.csv",message);
    saveToCsvFile("fordBellmanList.csv",message);
    saveToCsvFile("fordBellmanMatrix.csv",message);
}

long long Test::calculateTime(int algorithm) {
    long long time;

    auto timeStart = std::chrono::high_resolution_clock::now();
    switch (algorithm) {
        case 1:
            Prim::getMST(matrix);
            break;
        case 2:
            Prim::getMST(list);
            break;
        case 3:
            Kruskal::getMST(matrix);
            break;
        case 4:
            Kruskal::getMST(list);
            break;
        case 5:
            Dijkstra::getSPT(matrix, 0);
            break;
        case 6:
            Dijkstra::getSPT(list, 0);
            break;
        case 7:
            BellmanFord::getSPT(matrix, 0);
            break;
        case 8:
            BellmanFord::getSPT(list, 0);
            break;
        default:
            break;
    }
    auto timeEnd =std::chrono::high_resolution_clock::now();
    time = std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count();
    return time;
}

