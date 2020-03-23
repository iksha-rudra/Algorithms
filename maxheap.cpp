#include "maxheap.h"
#include "utility.h"

MaxHeap::MaxHeap()
{

}

void MaxHeap::heapify(int A[], int i, int n)
{
    int l = 2*i+1;

    int r = 2*i+2;

    int largest;

    if ( l < n && A[l] > A[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if( r < n && A[r] > A[largest])
    {
        largest = r;
    }

    if( largest != i)
    {
        Utility::swap(A[i],A[largest]);
    }
    else
    {
        return;
    }

    heapify(A, largest, n);
}

void MaxHeap::buildHeap(int A[], int n)
{
    for(int i = n/2-1; i >= 0; i--)
    {
        heapify(A, i, n);
    }
}

void MaxHeap::sort(int A[], int n)
{
    buildHeap(A, n);

    int j = 0;

    for(int i = n-1; i > 0; i--)
    {
        Utility::swap(A[0],A[i]);

        j++;

        heapify(A,0,n-j);
    }
}

int MaxHeap::extractMax(int A[], int n)
{

}

int MaxHeap::increaseKey(int A[], int n)
{

}

int MaxHeap::decreaseKey(int A[], int n)
{

}

int MaxHeap::insert(int A[], int n)
{

}



