#ifndef SORTING_HPP
#define SORTING_HPP

class Sorting
{
public:
    Sorting();
    ~Sorting();
    
    static void display(int A[], int size);
    
    static void merge(int A[],int p, int q, int r);
    static void mergeSort(int A[], int p, int r);
    
    static void quickSort(int A[], int p, int r);
    static int partition(int A[],int p, int r);
    inline static void swap(int& a, int& b);

};

#endif // SORTING_HPP
