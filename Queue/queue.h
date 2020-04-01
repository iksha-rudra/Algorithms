#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_MAX 50

class Queue
{

public:
    Queue();

    void enqueue(int item);

    int dequeue();

    void display();

private:
    int m_Array[QUEUE_MAX];

    int m_front;

    int m_rear;
};

#endif // QUEUE_H
