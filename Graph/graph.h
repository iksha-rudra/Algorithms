#ifndef GRAPH_H
#define GRAPH_H


class Graph
{

public:
    // A structure to represent an adjacency list node
    struct AdjListNode
    {
        int dest;
        struct AdjListNode* next;
    };

    // A structure to represent an adjacency list
    struct AdjList
    {
        struct AdjListNode *head;
    };

    Graph();

private:
    int V;
    struct AdjList* array;
};

#endif // GRAPH_H
