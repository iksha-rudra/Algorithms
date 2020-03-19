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

    std::generate(v1.begin(),v1.end(),[]{return rand() % 1000;});

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

void Utility::swap(int& a, int& b)
{
    int temp = a;

    a = b;

    b = temp;
}
