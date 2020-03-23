#ifndef HEAP_H
#define HEAP_H


class MaxHeap
{

public:

    MaxHeap();

    static void heapify(int A[],int i,int n);

    static void buildHeap(int A[], int n);

    static void sort(int A[], int n);

    static int extractMax(int A[], int n);

    static int increaseKey(int A[], int n);

    static int decreaseKey(int A[], int n);

    static int insert(int A[], int n);
};

#endif // HEAP_H
