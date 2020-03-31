#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "graph.h"

class DirectedGraph : public Graph
{
public:
    DirectedGraph(int V);

    void createAdjList(Graph::Edge edges[], int E);
};

#endif // DIRECTEDGRAPH_H
