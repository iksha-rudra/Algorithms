#include "distanceheap.h"
#include <bits/stdc++.h>

DistanceHeap::DistanceHeap():
    m_size(0)
{

}

DistanceHeap::Node DistanceHeap::extractMin()
{
    Node min;

    if( !m_size )
    {
        return Node();
    }
    else
    {
        min = m_Array[0];

        m_size--;

        m_Array[0] = m_Array[m_size];

        heapify(0, m_size);
    }

    return min;
}

DistanceHeap::DistanceHeap(Node A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_Array.push_back(A[i]);
    }

    m_size = size;

    buildHeap();
}

void DistanceHeap::buildHeap()
{
    for(int i = m_size/2-1; i >= 0; i--)
    {
        heapify(i,m_size);
    }
}

bool DistanceHeap::isEmpty()
{
    if( !m_size )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void DistanceHeap::insert(Node data)
{
    int i;

    for( i = 0; i < m_size; i++ )
    {
        if( m_Array[i].vertex == data.vertex)
        {
            return;
        }
    }

    Node temp;

    temp.vertex = data.vertex;

    temp.dist = INT_MAX;

    m_Array.push_back(temp);

    m_size++;

    decreaseKey(data);
}

void DistanceHeap::decreaseKey(Node data)
{
    int i;

    for( i = 0; i < m_size; i++ )
    {
        if( m_Array[i].vertex == data.vertex)
        {
            break;
        }
    }

    if( i == m_size)
    {
        return;
    }

    if(m_Array[i].dist < data.dist)
    {
        printf("Error:\n");

        return;
    }

    m_Array[i].dist = data.dist;

    while( i > 0 &&
           m_Array[parent(i)].dist > m_Array[i].dist )
    {
        swap(m_Array[parent(i)] , m_Array[i]);

        i = parent(i);
    }
}

void DistanceHeap::heapify(int i, int n)
{
    int l = left(i);

    int r = right(i);

    int smallest;

    if ( l < n && m_Array[l].dist < m_Array[i].dist)
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if( r < n && m_Array[r].dist < m_Array[smallest].dist)
    {
        smallest = r;
    }

    if( smallest != i)
    {
        swap(m_Array[i],m_Array[smallest]);
    }
    else
    {
        return;
    }

    heapify(smallest,n);
}

int DistanceHeap::parent(int i)
{
    return (i-1)/2;
}

int DistanceHeap::left(int i)
{
    return (2*i+1);
}

int DistanceHeap::right(int i)
{
    return (2*i+2);
}

void DistanceHeap::swap(Node &a, Node &b)
{
    Node temp = a;

    a = b;

    b = temp;
}
