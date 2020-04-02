#ifndef DISTANCEHEAP_H
#define DISTANCEHEAP_H

#define MAX_VERTEX 50

class DistanceHeap
{
public:
    struct Node
    {
        int vertex;

        int dist;

        Node():
            vertex(-1),dist(-1)
        {

        }

        Node(int v, int d):
            vertex(v),dist(d)
        {

        }
    };

    DistanceHeap();

    DistanceHeap(Node A[], int size);

    Node extractMin();

    void decreaseKey(Node data);

    void insert(Node data);

    void swap(Node &a, Node &b);

    void buildHeap();

private:

    Node m_Array[MAX_VERTEX];

    int m_size;

    void heapify(int i, int n);

    int parent(int i);

    int left(int i);

    int right(int i);
};

#endif // DISTANCEHEAP_H
