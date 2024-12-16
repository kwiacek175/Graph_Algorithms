#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

class AdjacencyList {
public:
    struct Edge {
        unsigned int dest;
        int weight;
        Edge(unsigned int dest, int weight) : dest(dest), weight(weight) {};
    };
    struct EdgeList {
        int size = 0;
        Edge *list = nullptr;
    };
private:
    int vertices;
    EdgeList *adjList;
public:
    explicit AdjacencyList(int vertices);
    ~AdjacencyList();
    void addEdge(unsigned int startVertex,unsigned int endVertex, int weight);

    int getVertices() const;
    EdgeList *getAdjList() const;

    void print();
};

#endif
