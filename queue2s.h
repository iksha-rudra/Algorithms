#ifndef QUEUE2S_H
#define QUEUE2S_H

#include "linkedstack.h"

class Queue2S
{
public:
    Queue2S();

    void enqueue(int item);

    int dequeue();

    void display();

private:

    LinkedStack S1,S2;
};

#endif // QUEUE2S_H
