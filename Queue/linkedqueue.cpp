#include "linkedqueue.h"
#include <stdio.h>

LinkedQueue::LinkedQueue():
        m_head(nullptr)
{

}

void LinkedQueue::_print(LinkedQueue::Node *temp)
{
    if( temp )
    {
        printf("%d-->",temp->data);

        _print(temp->link);
    }
}

void LinkedQueue::display()
{
    Node *temp = m_head;

    printf("Elements of linkedQueue are: ");

    _print(temp);
}

int LinkedQueue::dequeue()
{
    int item = -1;

    if( !m_head )
    {
        printf("Underflow\n");
    }
    else
    {
        Node *temp = m_head;

        m_head = m_head->link;

        item = temp->data;

        delete temp;
    }

    return item;
}

void LinkedQueue::enqueue(int data)
{
    Node *newNode = new Node(data);

    if(!m_head)
    {
        m_head = newNode;

        return;
    }

    Node *temp = m_head;

    while(temp->link)
    {
        temp = temp->link;
    }

    temp->link = newNode;
}
