#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph
{

public:

    enum Color
    {
        Color_White,

        Color_Grey,

        Color_Black
    };

    enum Type
    {
        Type_Undirected,

        Type_Directed
    };

    struct ENode
    {
        int dest;

        int weight;

        ENode* next;

        ENode(int dest, int weight)
        {
            this->dest = dest;

            this->weight = weight;

            this->next = nullptr;
        }
    };

    struct VNode
    {
        int vID;

        int predec;

        int distFS;

        Color col;

        ENode* head;

        VNode(int vertex)
        {
            this->vID = vertex;

            this->predec = -1;

            this->distFS = INT_MAX;

            this->col = Color_White;

            this->head = nullptr;
        }
    };

    Graph(Type type);

    virtual ~Graph();

    void display();

    void printShortestPath(int u, int v);

    void addEdge(int u, int v, int weight=0);

    void addVertex(int v);

    void removeVertex(int v);

    void removeEdge(int u, int v);

    vector<int> getNeighbours(int v);

    int getNumberOfVertices();

    int getNumberOfEdges();

    int getEdgeWeight(int u, int v);

    void setEdgeWeight(int u, int v, int weight);

    void BFS(int v);

    void DFS(int v);

    void digkstra(int v);

protected:

    Type m_type;

    unordered_map<int, int> m_map;

    vector<VNode*> m_head;

    void _addEdge(int u, int v, int weight);

    void _initSingleSource(int v);

    void _deleteEdgeNodes(ENode *temp);

    void _dfsVisit(int v);

    bool _contains(vector<int> list, int key);

    VNode *_getVertex(int v);
};

#endif // GRAPH_H
