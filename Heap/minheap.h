#ifndef MINHEAP_H
#define MINHEAP_H

#define HEAP_SIZE 100

class MinHeap
{
public:
    MinHeap();

    MinHeap(int A[], int size);

    int extractMin();

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

#endif // MINHEAP_H
