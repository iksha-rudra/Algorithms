#include "directedgraph.h"

DirectedGraph::DirectedGraph(int V):
    Graph(V)
{

}

void DirectedGraph::createAdjList(Graph::Edge edges[], int E)
{
    for( int i = 0; i < E; i++ )
    {
        _createAdjList(edges[i].src, edges[i].dest, edges[i].weight);
    }
}

