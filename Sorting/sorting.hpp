#ifndef SORTING_H
#define SORTING_H

class Sorting
{

public:
    Sorting();

    ~Sorting();
    
    static void mergeSort(int A[], int p, int r);
    
    static void quickSort(int A[], int p, int r);

    static void insertionSort(int A[], int n);

    static void selectionSort(int A[], int n);

    static void bubbleSort(int A[], int n);

    static void countingSort(int A[], int n,  int range);
};

#endif // SORTING_HPP
