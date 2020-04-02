#include "graph.h"
#include <stdio.h>
#include "Queue/linkedqueue.h"
#include "Stack/linkedstack.h"
#include "distanceheap.h"

Graph::Graph(Type type):
    m_type(type)
{

}

Graph::~Graph()
{
    for( int i = 0 ; i < m_head.size(); i++ )
    {
        ENode *head = m_head[i]->head;

        _deleteEdgeNodes(head);

        delete m_head[i];
    }
}

void Graph::_deleteEdgeNodes(ENode *temp)
{
    if(temp)
    {
        _deleteEdgeNodes(temp->next);

        delete temp;
    }
}

void Graph::_initSingleSource(int v)
{
    VNode *vNode;

    for( int i = 0; i < m_head.size(); i++ )
    {
        vNode = m_head[i];

        vNode->predec = -1;

        vNode->distFS = INT_MAX;

        vNode->col = Color_White;
    }

    vNode = _getVertex(v);

    vNode->predec = -1;

    vNode->distFS = 0;

    vNode->col = Color_Grey;
}

void Graph::_addEdge(int u, int v, int weight)
{
    VNode *uNode = _getVertex(u);

    ENode *newNode = new ENode(v,weight);

    ENode *eNode = uNode->head;

    if( !eNode )
    {
        uNode->head = newNode;
    }
    else
    {
        while(eNode->next)
        {
            eNode = eNode->next;
        }

        eNode->next = newNode;
    }
}

void Graph::display()
{
    for( unsigned i = 0; i < m_head.size(); i++)
    {
        VNode *vNode = m_head[i];

        ENode *e = vNode->head;

        while(e)
        {
            printf("( %d, %d, %d ) ", vNode->vID, e->dest, e->weight );

            e = e->next;
        }

        printf("\n");
    }
}

void Graph::printShortestPath(int u, int v)
{
    if( u == v)
    {
        printf("%d-->",u);
    }
    else if( _getVertex(v)->predec == -1)
    {
        printf("No path from %d to %d exists.\n", u,v);
    }
    else
    {
        printShortestPath(u, _getVertex(v)->predec);

        printf("%d-->",v);
    }
}

void Graph::addEdge(int u, int v, int weight)
{
    _addEdge(u, v, weight);

    if( m_type == Type_Undirected)
    {
        _addEdge(v, u, weight);
    }
}

void Graph::addVertex(int v)
{
    VNode *newNode = new VNode(v);

    int index = m_head.size();

    m_map[v] = index;

    m_head.push_back(newNode);
}

void Graph::removeVertex(int v)
{

}

void Graph::removeEdge(int u, int v)
{

}

vector<int> Graph::getNeighbours(int v)
{
    vector <int> listVertex;

    VNode *vNode = _getVertex(v);

    ENode *eNode = vNode->head;

    while(eNode)
    {
        listVertex.push_back(eNode->dest);

        eNode = eNode->next;
    }

    return listVertex;
}

int Graph::getNumberOfVertices()
{

}

int Graph::getNumberOfEdges()
{

}

int Graph::getEdgeWeight(int u, int v)
{
    int weight = -1;

    VNode *uNode = _getVertex(u);

    ENode *eNode = uNode->head;

    while(eNode)
    {
        if( eNode->dest == v)
        {
            weight = eNode->weight;
        }

        eNode = eNode->next;
    }

    return weight;
}

void Graph::setEdgeWeight(int u, int v, int weight)
{

}

void Graph::BFS(int v)
{
    _initSingleSource(v);

    LinkedQueue<int> Q;

    Q.enqueue(v);

    while( !Q.isEmpty() )
    {
        int q = Q.dequeue();

        VNode *qNode = _getVertex(q);

        ENode *eNode = qNode->head;

        while( eNode )
        {
            int w = eNode->dest;

            VNode *wNode = _getVertex(w);

            if( wNode->col == Color_White )
            {
                wNode->predec = q;

                wNode->distFS = qNode->distFS + 1;

                wNode->col = Color_Grey;

                Q.enqueue(w);
            }

            eNode = eNode->next;
        }

        qNode->col = Color_Black;
    }
}

void Graph::_dfsVisit(int v)
{
    VNode* vNode = _getVertex(v);

    ENode *eNode = vNode->head;

    while( eNode )
    {
        int w = eNode->dest;

        VNode* wNode = _getVertex(w);

        if( wNode->col == Color_White )
        {
            wNode->predec = w;

            wNode->col = Color_Grey;

            _dfsVisit(w);
        }

        eNode = eNode->next;
    }

    vNode->col = Color_Black;
}

bool Graph::_contains(vector<int> list, int key)
{
    for(int i = 0; i < list.size(); i++ )
    {
        if( list.at(i) == key )
        {
            return true;
        }
    }

    return false;
}

inline Graph::VNode *Graph::_getVertex(int v)
{
    VNode* vNode = m_head[m_map[v]];

    return vNode;
}

void Graph::DFS(int v)
{
    _initSingleSource(v);

    _dfsVisit(v);
}

void Graph::digkstra(int v)
{
    _initSingleSource(v);

    vector<int> selectedList;

    DistanceHeap dHeap;

    for(int i=0; i < m_head.size(); i++)
    {
        VNode *vNode = m_head[i];

        DistanceHeap::Node dNode(vNode->vID,vNode->distFS);

        dHeap.insert(dNode);
    }

    while(!dHeap.isEmpty())
    {
        DistanceHeap::Node dNode = dHeap.extractMin();

        int u = dNode.vertex;

        selectedList.push_back(u);

        vector<int> listNeighbours = getNeighbours(u);

        for(int i = 0; i< listNeighbours.size(); i++)
        {
            int v = listNeighbours.at(i);

            if( !_contains(selectedList,v) )
            {
                int weight = getEdgeWeight(u, v);

                VNode* uNode = _getVertex(u);

                VNode *vNode = _getVertex(v);

                if( vNode->distFS > ( uNode->distFS + weight ) )
                {
                    vNode->distFS = uNode->distFS + weight;

                    vNode->predec = u;

                    DistanceHeap::Node dNode(vNode->vID, vNode->distFS);

                    dHeap.decreaseKey(dNode);
                }
            }
        }
    }
}
