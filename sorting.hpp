#ifndef SORTING_H
#define SORTING_H

class Sorting
{

public:
    Sorting();

    ~Sorting();
    
    static void merge(int A[],int p, int q, int r);

    static void mergeSort(int A[], int p, int r);
    
    static void quickSort(int A[], int p, int r);

    static int partition(int A[],int p, int r);

    static int quickSelect(int A[], int p, int r, int k);
};

#endif // SORTING_HPP
