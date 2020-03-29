#include "sorting.hpp"
#include "General/utility.h"
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
    int i,j,key;

    for(j=1; j<n; j++)
    {
        key = A[j];

        for(i=j-1; i>=0 && A[i] > key; i--)
        {
            A[i+1] = A[i];
        }

        A[i+1] = key;
    }
}

void Sorting::selectionSort(int A[], int n)
{
    int i,j,min;

    for(i=0; i < n; i++)
    {
        min = i;

        for(j=i+1; j < n; j++)
        {
            if( A[j] < A[min])
            {
                min = j;
            }
        }

        Utility::swap(A[i],A[min]);
    }
}

void Sorting::bubbleSort(int A[], int n)
{
    int i,j,swapped;

    for(i=0; i<n; i++)
    {
        swapped = 0;

        for(j=0;j<n-i-1;j++)
        {
            if( A[j] > A[j+1])
            {
                Utility::swap(A[j],A[j+1]);

                swapped = 1;
            }
        }

        if( !swapped )
        {
            break;
        }
    }
}

void Sorting::countingSort(int A[], int n, int range)
{
    int B[range];

    int C[n];

    int i;

    for(i=0; i<range; i++)
    {
        B[i] = 0;
    }

    for(i=0; i<n; i++)
    {
        C[i] = 0;
    }

    for(i=0; i<n; i++)
    {
        B[A[i]]++;
    }

    for(i=1; i<range; i++)
    {
        B[i] = B[i]+B[i-1];
    }

    for(i=0; i<n; i++)
    {
        C[B[A[i]]-1]=A[i];

        B[A[i]]--;
    }

    for(i=0; i<n; i++)
    {
        A[i] = C[i];
    }
}
