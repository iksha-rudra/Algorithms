#include "graph.h"
#include <stdio.h>
#include "Queue/linkedqueue.h"
#include "Stack/linkedstack.h"

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

void Graph::BFS(int v)
{
    bool visited[V];

    LinkedQueue<int> Q;

    for( int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    Q.enqueue(v);

    visited[v] = true;

    printf("%d-->",v);

    while(!Q.isEmpty())
    {
        int u = Q.dequeue();

        Node *t = m_head[u];

        while(t)
        {
            int w = t->dest;

            if( !visited[w] )
            {
                visited[w] = true;

                printf("%d-->",w);

                Q.enqueue(w);
            }

            t = t->next;
        }
    }

    printf("\n");
}

void Graph::DFS(int v)
{
    bool visited[V];

    LinkedStack S;

    for( int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    S.push(v);

    while(!S.isEmpty())
    {
        int u = S.pop();

        if(visited[u])
        {
            continue;
        }

        visited[u] = true;

        printf("%d-->",u);

        Node *t = m_head[u];

        while(t)
        {
            int w = t->dest;

            S.push(w);

            t = t->next;
        }
    }

    printf("\n");
}

void Graph::_createAdjList(int src, int dest, int weight)
{
    Node *newNode = new Node(dest,weight);

    newNode->next = m_head[src];

    m_head[src] = newNode;
}
