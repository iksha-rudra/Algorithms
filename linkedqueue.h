#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H


class LinkedQueue
{
public:
    LinkedQueue();

    struct Node
    {
        int data;

        struct Node *link;

        Node(int d)
        {
            data = d;

            link = nullptr;
        }
    };

    void display();

    void enqueue(int item);

    int dequeue();

private:

    Node *m_head;

    void _print(LinkedQueue::Node *temp);
};

#endif // LINKEDQUEUE_H
