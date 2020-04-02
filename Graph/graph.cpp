#include "graph.h"
#include <stdio.h>
#include "Queue/linkedqueue.h"
#include "Stack/linkedstack.h"

Graph::Graph(int V, Type type):
    m_type(type)
{
    _init(V);
}

Graph::~Graph()
{
    for( int i = 0 ; i < V; i++ )
    {
        ENode *head = m_head[i]->head;

        _deleteEdgeNodes(head);

        delete m_head[i];
    }

    delete[] m_head;
}

void Graph::_deleteEdgeNodes(ENode *temp)
{
    if(temp)
    {
        _deleteEdgeNodes(temp->next);

        delete temp;
    }
}

void Graph::_init(int V)
{
    m_head = new VNode*[V]();

    this->V = V;

    for( int i = 0; i < V; i++ )
    {
        m_head[i] = new VNode();
    }
}

void Graph::_initSingleSource(int s)
{
    for( int i = 0; i < V; i++ )
    {
        m_head[i]->predec = -1;

        m_head[i]->distFS = INT_MAX;

        m_head[i]->col = Color_White;
    }

    m_head[s]->predec = -1;

    m_head[s]->distFS = 0;

    m_head[s]->col = Color_Grey;
}

void Graph::_addEdge(int src, int dest, int weight)
{
    ENode *newNode = new ENode(dest,weight);

    ENode *e = m_head[src]->head;

    if( !e )
    {
        m_head[src]->head = newNode;
    }
    else
    {
        while(e->next)
        {
            e = e->next;
        }

        e->next = newNode;
    }
}

void Graph::display()
{
    for( int i = 0; i < V; i++)
    {
        ENode *e = m_head[i]->head;

        while(e)
        {
            printf("( %d, %d, %d ) ", i, e->dest, e->weight );

            e = e->next;
        }

        printf("\n");
    }
}

void Graph::printShortestPath(int s, int v)
{
    if( s == v)
    {
        printf("%d-->",s);
    }
    else if( m_head[v]->predec == -1)
    {
        printf("No path from %d to %d exists.\n", s,v);
    }
    else
    {
        printShortestPath(s, m_head[v]->predec);

        printf("%d-->",v);
    }
}

void Graph::addEdge(int src, int dest, int weight)
{
    _addEdge(src, dest, weight);

    if( m_type == Type_Undirected)
    {
        _addEdge(dest, src, weight);
    }
}

void Graph::BFS(int s)
{
    _initSingleSource(s);

    LinkedQueue<int> Q;

    Q.enqueue(s);

    while( !Q.isEmpty() )
    {
        int q = Q.dequeue();

        VNode *u = m_head[q];

        ENode *e = m_head[q]->head;

        while( e )
        {
            int w = e->dest;

            VNode *v = m_head[w];

            if( v->col == Color_White )
            {
                v->predec = q;

                v->distFS = u->distFS + 1;

                v->col = Color_Grey;

                Q.enqueue(w);
            }

            e = e->next;
        }

        u->col = Color_Black;
    }
}

void Graph::_dfsVisit(int s)
{
    VNode* u = m_head[s];

    ENode *e = u->head;

    while( e )
    {
        int w = e->dest;

        VNode* v = m_head[w];

        if( v->col == Color_White )
        {
            v->predec = s;

            v->col = Color_Grey;

            _dfsVisit(w);
        }

        e = e->next;
    }

    u->col = Color_Black;
}

void Graph::DFS(int s)
{
    _initSingleSource(s);

    _dfsVisit(s);
}
