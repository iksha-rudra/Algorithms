#include <stdio.h>
#include "utility.h"
#include "maxheap.h"
#include "sorting.hpp"

#define MAX 10

int main()
{
    int A[MAX];

    Utility::fillArrayWithRandom(A,MAX);

    Utility::display(A,MAX);

    Sorting::bubbleSort(A,MAX);

    Utility::display(A,MAX);

//    MaxHeap Mheap(A,MAX);

////    Mheap.sort();

//    Mheap.display();

//    printf("%d\n",Mheap.extractMax());

//    Mheap.increaseKey(3,999);

//    Mheap.decreaseKey(3,0);

//    printf("%d\n",Mheap.extractMax());

	return 0;
}
