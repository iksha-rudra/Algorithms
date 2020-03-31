#include "undirectedgraph.h"

UndirectedGraph::UndirectedGraph(int V):
    Graph(V)
{

}

void UndirectedGraph::createAdjList(Graph::Edge edges[], int E)
{
    for( int i = 0; i < E; i++ )
    {
        _createAdjList(edges[i].src, edges[i].dest, edges[i].weight);

        _createAdjList(edges[i].dest, edges[i].src, edges[i].weight);
    }
}

