#include <stdio.h>
#include "sorting.hpp"
#include "utility.h"
#include "recursion.h"

#define MAX 50

int main()
{
    int A[MAX];

    Utility::fillArrayWithRandom(A,MAX);
    
    Utility::display(A,MAX);

    Sorting::mergeSort(A,0,MAX-1);

    Utility::display(A,MAX);

    Utility::fillArrayWithRandom(A,MAX);

    Utility::display(A,MAX);

    Sorting::quickSort(A,0,MAX-1);

    Utility::display(A,MAX);

    Recursion::HanoiMoveDisk(5);

	return 0;
}
