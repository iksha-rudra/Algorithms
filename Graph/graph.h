#ifndef GRAPH_H
#define GRAPH_H

class Graph
{

public:
    struct Node
    {
        int dest;

        int weight;

        Node* next;

        Node(int dest, int weight)
        {
            this->dest = dest;

            this->weight = weight;

            this->next = nullptr;
        }
    };

    struct Edge
    {
        int src;

        int dest;

        int weight;

        Edge(int src,int dest, int weight):
            src(src),dest(dest),weight(weight)
        {

        }

        Edge()
        {

        }
    };

    Graph(int V);

    virtual ~Graph();

    void display();

    virtual void createAdjList(Edge edges[], int E)=0;

protected:

    int V;

    Node **m_head;

    void _createAdjList(int src, int dest, int weight);

    void _init(int V);
};

#endif // GRAPH_H
