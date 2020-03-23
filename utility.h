#ifndef UTILITY_H
#define UTILITY_H


class Utility
{
public:
    Utility();

    static void fillArrayWithRandom( int A[], int size );

    static void display(int A[], int size);

    static void swap(int& a, int& b);

    static bool testSorted(int A[], int size);

    static int quickSelect(int A[], int p, int r, int k);

    static int partition(int A[],int p, int r);

    static void merge(int A[],int p, int q, int r);
};

#endif // UTILITY_H
