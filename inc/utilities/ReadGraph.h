#ifndef READGRAPH_H
#define READGRAPH_H

#include "structures/EdgesList.h"

class ReadGraph {
public:
    static EdgeList readGraph(const std::string& filename);
};
#endif
