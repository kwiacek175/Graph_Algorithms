#ifndef EDGESLIST_H
#define EDGESLIST_H

#include <iostream>
#include <fstream>

class EdgeList {
public:
    struct Edge {
        int start;
        int end;
        int weight;

        Edge(){
            start = 0;
            end = 0;
            weight = 0;
        };
        Edge(int start, int end, int weight) : start(start), end(end), weight(weight) {};
    };

    Edge* edges;
    unsigned int vertices;
    unsigned int edgesNum;
    EdgeList(unsigned int vertices, unsigned int edgesNum, Edge* edges)
        : vertices(vertices), edgesNum(edgesNum), edges(edges){};

    virtual ~EdgeList() {
        delete[] edges;
    }

    void addEdge(Edge edge){
        if(edgesNum == 0){
            edges = new Edge[1]{edge};
            edgesNum++;
        } else {
            int newSize = sizeof(Edge) * (edgesNum + 1);
            Edge* temp = static_cast<Edge*>(std::realloc(edges, newSize));
            if (temp == nullptr) {
                std::cerr << "Failed to reallocate memory." << std::endl;
                return;
            }
            edges = temp;
            edges[edgesNum++] = edge;
        }
    }

    void print() const {
        for(int i = 0; i < edgesNum; i++){
            std::cout << edges[i].start << " " << edges[i].end << " "<< edges[i].weight << "\n";
        }
    }
};
#endif
