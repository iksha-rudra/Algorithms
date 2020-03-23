#include <stdio.h>
#include "sorting.hpp"
#include "utility.h"
#include "recursion.h"
#include "maxheap.h"

#define MAX 10

int main()
{
    int A[MAX];

    Utility::fillArrayWithRandom(A,MAX);
    
    Utility::display(A,MAX);

    MaxHeap::sort(A,MAX);
//    MaxHeap::buildHeap(A,MAX);

    Utility::display(A,MAX);

    bool sorted = Utility::testSorted(A,MAX);

    if( sorted )
    {
        printf("Elements are sorted\n");
    }
    else
    {
        printf("Elements are not sorted\n");
    }


//    Sorting::mergeSort(A,0,MAX-1);

//    Utility::display(A,MAX);

//    Utility::fillArrayWithRandom(A,MAX);

//    Utility::display(A,MAX);

//    Sorting::quickSort(A,0,MAX-1);

//    Utility::display(A,MAX);

//    Recursion::HanoiMoveDisk(5);

	return 0;
}
