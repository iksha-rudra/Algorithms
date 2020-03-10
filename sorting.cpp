#include "sorting.hpp"
#include <stdio.h>

Sorting::Sorting()
{
    
}

Sorting::~Sorting()
{
    
}

void Sorting::display(int A[], int size)
{
    printf("Elements are: ");
    for(int i=0;i<size;i++)
    {
        printf("%d->",A[i]);
    }
    printf("\n");
}

void Sorting::merge(int A[],int p, int q, int r)
{
    int m = q-p;
    int n = r-q+1;
    
    int L[m+1];
    int R[n+1];
    
    int i;
    int j;
    int k;
    
    for(i=0; i < m; i++)
    {
        L[i] = A[p+i];
    }
    L[i] = 9999;
    
    for(j=0; j < n; j++)
    {
        R[j] = A[q+j];
    }
    R[j] = 9999;
    
    for(k=p,i=0,j=0; k <= r ; k++)
    {
        if( L[i] < R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

void Sorting::mergeSort(int A[], int p, int r)
{
    if( p < r )
    {
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q+1,r);
    }
}

void Sorting::quickSort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = partition(A,p,r);
        quickSort(A,p,q-1);
        quickSort(A,q+1,r);
    }
}

void Sorting::swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Sorting::partition(int A[], int p, int r)
{
    int i;
    int j;
    
    for(j = p, i = p-1; j < r; j++ )
    {
        if(A[j] < A[r])
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    i++;
    swap(A[i],A[r]);
    
    return i;
}