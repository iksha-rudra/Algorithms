#include <stdio.h>
#include "General/utility.h"
#include "Heap/minheap.h"
#include "Sorting/sorting.hpp"

#define MAX 10

int main()
{
    int A[MAX];

    Utility::fillArrayWithRandom(A,MAX);

    Utility::display(A,MAX);

    MinHeap Mheap(A,MAX);

    Mheap.display();

    for(int i=0; i<MAX; i++)
    {
        printf("%d\n",Mheap.extractMin());
    }

	return 0;
}
