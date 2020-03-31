#include "graph.h"
#include <stdio.h>

Graph::Graph(int V)
{
    _init(V);
}

Graph::~Graph()
{
    for( int i = 0 ; i < V; i++ )
    {
        delete[] m_head[i];
    }

    delete[] m_head;
}

void Graph::_init(int V)
{
    m_head = new Node*[V]();

    this->V = V;

    for( int i = 0; i < V; i++ )
    {
        m_head[i] = nullptr;
    }
}

void Graph::display()
{
    for( int i = 0; i < V; i++)
    {
        Node *t = m_head[i];

        while(t)
        {
            printf("( %d, %d, %d ) ", i, t->dest, t->weight );

            t = t->next;
        }

        printf("\n");
    }
}

void Graph::_createAdjList(int src, int dest, int weight)
{
    Node *newNode = new Node(dest,weight);

    newNode->next = m_head[src];

    m_head[src] = newNode;
}
