#include "minheap.h"
#include "General/utility.h"
#include <stdio.h>
#include <bits/stdc++.h>

MinHeap::MinHeap():
    m_size(0)
{

}

MinHeap::MinHeap(vector<Point> pointList)
{

}

MinHeap::MinHeap(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_Array[i] = A[i];
    }

    m_size = size;

    buildHeap();
}

int MinHeap::extractMin()
{
    int min;

    if( !m_size )
    {
        return -1;
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

void MinHeap::increaseKey(int i, int key)
{
    if( i < 0 && m_size >= i)
    {
        return;
    }

    if(m_Array[i] > key)
    {
        printf("Error:\n");

        return;
    }

    m_Array[i] = key;

    heapify(i, m_size);
}

void MinHeap::decreaseKey(int i, int key)
{
    if( i < 0 && m_size >= i)
    {
        return;
    }

    if(m_Array[i] < key)
    {
        printf("Error:\n");

        return;
    }

    m_Array[i] = key;

    while( i > 0 &&
           m_Array[parent(i)] > m_Array[i])
    {
        Utility::swap(m_Array[parent(i)] , m_Array[i]);

        i = parent(i);
    }
}

void MinHeap::insert(int key)
{
    m_Array[m_size] = INT_MAX;

    m_size++;

    decreaseKey(m_size-1,key);
}

void MinHeap::display()
{
    Utility::display(m_Array, m_size);
}

void MinHeap::heapify(int i, int n)
{
    int l = left(i);

    int r = right(i);

    int smallest;

    if ( l < n && m_Array[l] < m_Array[i])
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if( r < n && m_Array[r] < m_Array[smallest])
    {
        smallest = r;
    }

    if( smallest != i)
    {
        Utility::swap(m_Array[i],m_Array[smallest]);
    }
    else
    {
        return;
    }

    heapify(smallest,n);
}

void MinHeap::buildHeap()
{
    for(int i = m_size/2-1; i >= 0; i--)
    {
        heapify(i,m_size);
    }
}

int MinHeap::parent(int i)
{
    return (i-1)/2;
}

int MinHeap::left(int i)
{
    return (2*i+1);
}

int MinHeap::right(int i)
{
    return (2*i+2);
}

