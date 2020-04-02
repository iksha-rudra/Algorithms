#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

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
        int predec;

        int distFS;

        Color col;

        ENode* head;

        VNode()
        {
            this->predec = -1;

            this->distFS = INT_MAX;

            this->col = Color_White;

            this->head = nullptr;
        }
    };

    Graph(int V, Type type = Type_Undirected);

    virtual ~Graph();

    void display();

    void printShortestPath(int s, int v);

    void addEdge(int src, int dest, int weight);

    void BFS(int s);

    void DFS(int s);

protected:

    int V;

    Type m_type;

    VNode **m_head;

    void _addEdge(int src, int dest, int weight);

    void _init(int V);

    void _initSingleSource(int s);

    void _deleteEdgeNodes(ENode *temp);

    void _dfsVisit(int s);
};

#endif // GRAPH_H
