#include "utility.h"
#include <vector>
#include <algorithm>
#include <time.h>


Utility::Utility()
{

}

void Utility::fillArrayWithRandom( int A[], int size )
{
    std::vector<int> v1(size);

    srand(time(0));

    std::generate(v1.begin(),v1.end(),[]{return rand() % 100;});

    std::vector<int>::iterator i1;

    int i = 0;

    for(i1 = v1.begin(); i1 != v1.end(); ++i1)
    {
        A[i++] = *i1;
    }
}

void Utility::display(int A[], int size)
{
    printf("Elements are: ");

    for(int i=0;i<size;i++)
    {
        printf("%d->",A[i]);
    }

    printf("\n");
}

void Utility::display(char A[], int size)
{
    printf("Elements are: ");

    for(int i=0;i<size;i++)
    {
        printf("%c->",A[i]);
    }

    printf("\n");
}

void Utility::swap(int& a, int& b)
{
    int temp = a;

    a = b;

    b = temp;
}

bool Utility::testSorted(int A[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        if( A[i] > A[i+1])
        {
            return false;
        }
    }

    return true;
}

int Utility::quickSelect(int A[], int p, int r, int k)
{
    if( p == r)
    {
        return A[p];
    }
    else
    {
        int q = partition(A, p, r);

        if( q < k)
        {
            return quickSelect(A, p, q-1, k);
        }
        else if( q > k)
        {
            return quickSelect(A, q+1, r, k-q);
        }
        else
        {
            return A[q];
        }
    }
}

int Utility::partition(int A[], int p, int r)
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

void Utility::merge(int A[],int p, int q, int r)
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
