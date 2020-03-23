#include "sorting.hpp"
#include "utility.h"
#include <stdio.h>

Sorting::Sorting()
{
    
}

Sorting::~Sorting()
{
    
}

void Sorting::mergeSort(int A[], int p, int r)
{
    if( p < r )
    {
        int q = (p+r)/2;

        mergeSort(A,p,q);

        mergeSort(A,q+1,r);

        Utility::merge(A,p,q+1,r);
    }
}

void Sorting::quickSort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = Utility::partition(A,p,r);

        quickSort(A,p,q-1);

        quickSort(A,q+1,r);
    }
}

void Sorting::insertionSort(int A[], int n)
{

}

void Sorting::selectionSort(int A[], int n)
{

}

void Sorting::bubbleSort(int A[], int n)
{

}
