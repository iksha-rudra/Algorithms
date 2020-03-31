#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <cstddef>
#include <stdio.h>

template <typename T>
class LinkedQueue
{
public:
    struct Node
    {
        T data;

        struct Node *link;

        Node(T d)
        {
            data = d;

            link = nullptr;
        }
    };

    LinkedQueue():
        m_head(nullptr)
    {

    }

    void display()
    {
        Node *temp = m_head;

        printf("Elements of linkedQueue are: ");

        _print(temp);
    }

    T dequeue()
    {
        T item;

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

    void enqueue(T data)
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

    bool isEmpty()
    {
        return !m_head;
    }

private:

    Node *m_head;

    void _print(LinkedQueue<T>::Node *temp)
    {
        if( temp )
        {
            printf("%d-->",temp->data);

            _print(temp->link);
        }
    }
};

#endif // LINKEDQUEUE_H
