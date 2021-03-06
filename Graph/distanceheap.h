#ifndef DISTANCEHEAP_H
#define DISTANCEHEAP_H

#include <vector>

using namespace std;

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

    bool isEmpty();

private:

    vector<Node> m_Array;

    int m_size;

    void heapify(int i, int n);

    int parent(int i);

    int left(int i);

    int right(int i);
};

#endif // DISTANCEHEAP_H
