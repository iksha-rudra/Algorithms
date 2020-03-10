#include <stdio.h>
#include "JEAlgorithms.hpp"
#include "sorting.hpp"

int main(int argc, char **argv)
{
	int A[]={4,5,6,1,2,3,11,99,23,65,47,28,14,22};
    
    Sorting::display(A,14);
//    Sorting::mergeSort(A,0,13);
    Sorting::quickSort(A,0,13);
    Sorting::display(A,14);

	return 0;
}
