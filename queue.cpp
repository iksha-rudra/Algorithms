#include "queue.h"
#include "stdio.h"

Queue::Queue():
    m_front(0),
    m_rear(0)
{

}

void Queue::enqueue(int item)
{
    m_rear = (m_rear+1)%QUEUE_MAX;

    if( m_rear == m_front)
    {
        printf("Queue is full\n");

        if( m_rear == 0)
        {
            m_rear = QUEUE_MAX-1;
        }
        else
        {
            m_rear = m_rear-1;
        }
    }
    else
    {
        m_Array[m_rear] = item;
    }
}

int Queue::dequeue()
{
    int item = -1;

    if( m_front == m_rear )
    {
        printf("Queue is empty\n");
    }
    else
    {
        m_front = (m_front+1)%QUEUE_MAX;

        item = m_Array[m_front];
    }

    return item;
}

void Queue::display()
{
    if( m_front == m_rear )
    {
        printf("Queue is empty\n");

        return;
    }

    printf("Elements are: ");

    int i = m_front;

    for(;;)
    {
        i = (i+1)%QUEUE_MAX;

        printf("%d->",m_Array[i]);

        if( i == m_rear)
        {
            break;
        }
    }

    printf("\n");
}

