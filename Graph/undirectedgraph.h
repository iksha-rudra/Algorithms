#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

class UndirectedGraph : public Graph
{
public:
    UndirectedGraph(int V);

    void createAdjList(Edge edges[], int E);
};

#endif // UNDIRECTEDGRAPH_H
