#include "maxheap.h"
#include "General/utility.h"
#include <stdio.h>

MaxHeap::MaxHeap():
    m_size(0)
{

}

MaxHeap::MaxHeap(int A[], int size)
{
    for(int i = 0; i < size; i++)
    {
        m_Array[i] = A[i];
    }

    m_size = size;

    buildHeap();
}

void MaxHeap::heapify(int i, int n)
{
    int l = left(i);

    int r = right(i);

    int largest;

    if ( l < n && m_Array[l] > m_Array[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if( r < n && m_Array[r] > m_Array[largest])
    {
        largest = r;
    }

    if( largest != i)
    {
        Utility::swap(m_Array[i],m_Array[largest]);
    }
    else
    {
        return;
    }

    heapify(largest,n);
}

void MaxHeap::buildHeap()
{
    for(int i = m_size/2-1; i >= 0; i--)
    {
        heapify(i,m_size);
    }
}

void MaxHeap::sort()
{
    buildHeap();

    int j=1;

    int n = m_size;

    for(int i = m_size-1; i > 0; i--)
    {
        Utility::swap(m_Array[0],m_Array[i]);

        j++;

        heapify(0, n-j);
    }
}

int MaxHeap::extractMax()
{
    int max;

    if( !m_size )
    {
        return -1;
    }
    else
    {
        max = m_Array[0];

        m_size--;

        m_Array[0] = m_Array[m_size];

        heapify(0, m_size);
    }

    return max;
}

void MaxHeap::increaseKey(int i, int key)
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

    while( i > 0 &&
           m_Array[parent(i)] < m_Array[i])
    {
        Utility::swap(m_Array[parent(i)] , m_Array[i]);

        i = parent(i);
    }
}

void MaxHeap::decreaseKey(int i, int key)
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

    heapify(i, m_size);
}

void MaxHeap::insert(int key)
{
    m_Array[m_size] = -9999;

    m_size++;

    increaseKey(m_size-1,key);
}

void MaxHeap::display()
{
    Utility::display(m_Array, m_size);
}

int MaxHeap::parent(int i)
{
    return (i-1)/2;
}

int MaxHeap::left(int i)
{
    return (2*i+1);
}

int MaxHeap::right(int i)
{
    return (2*i+2);
}



