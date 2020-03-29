#ifndef HEAP_H
#define HEAP_H

#define HEAP_SIZE 100

class MaxHeap
{

public:

    MaxHeap();

    MaxHeap(int A[], int size);

    void sort();

    int extractMax();

    void increaseKey(int i, int key);

    void decreaseKey(int i, int key);

    void insert(int key);

    void display();

private:

    int m_Array[HEAP_SIZE];

    int m_size;

    void heapify(int i, int n);

    void buildHeap();

    int parent(int i);

    int left(int i);

    int right(int i);
};

#endif // HEAP_H
