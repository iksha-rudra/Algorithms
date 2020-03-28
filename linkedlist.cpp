#include "linkedlist.h"
#include <stdio.h>

LinkedList::LinkedList():
    m_head(nullptr)
{

}

void LinkedList::insertAtStart(int data)
{
    Node *newNode = new Node(data);

    newNode->link = m_head;

    m_head = newNode;
}

void LinkedList::insertAtEnd(int data)
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

void LinkedList::insertAfterKey(int data, int key)
{
    Node *newNode = new Node(data);

    if(!m_head)
    {
        m_head = newNode;

        return;
    }

    Node *temp = m_head;

    while(temp->link && temp->data != key)
    {
        temp = temp->link;
    }

    if( temp->data == key )
    {
        newNode->link = temp->link;

        temp->link = newNode;
    }
    else
    {
        temp->link = newNode;
    }
}

void LinkedList::deleteHeadNode()
{
    if( !m_head )
    {
        return;
    }

    Node *temp = m_head;

    m_head = m_head->link;

    delete temp;
}

void LinkedList::deleteEndNode()
{
    if( !m_head )
    {
        return;
    }

    if( !m_head->link )
    {
        delete m_head;

        m_head = nullptr;
    }

    Node *cur = m_head;

    while( cur->link->link )
    {
        cur = cur->link;
    }

    delete cur->link;

    cur->link = nullptr;
}

void LinkedList::deleteNodeWithKey(int key)
{
    if( !m_head )
    {
        return;
    }

    if( m_head->data == key)
    {
        Node *temp = m_head;

        m_head = m_head->link;

        delete temp;
    }

    Node *cur = m_head;

    Node *prev = nullptr;

    while( cur->link && cur->data != key)
    {
        prev = cur;

        cur = cur->link;
    }

    if( cur->data == key)
    {
        prev->link = cur->link;

        delete cur;
    }
}

void LinkedList::reverseR()
{
    _reverseR(nullptr,m_head);
}

void LinkedList::_reverseR(LinkedList::Node *prev,
                           LinkedList::Node *cur)
{
    if(cur)
    {
        _reverseR(cur,cur->link);

        cur->link = prev;
    }
    else
    {
        m_head = prev;
    }
}

void LinkedList::reverse()
{
    Node *cur = m_head;

    Node *prev = nullptr;

    Node *next = nullptr;

    while( cur->link )
    {
        next = cur->link;

        cur->link = prev;

        prev = cur;

        cur = next;
    }

    m_head = prev;
}

void LinkedList::moveEndNodetoHead()
{
    if( !m_head || !m_head->link)
    {
        return;
    }

    Node *prev = nullptr;

    Node *cur = m_head;

    while( cur->link )
    {
        prev = cur;

        cur = cur->link;
    }

    cur->link = m_head;

    m_head = cur;

    prev->link = nullptr;
}

void LinkedList::print()
{
    Node *temp = m_head;

    printf("Elements of linkedList are: ");

    _print(temp);
}

void LinkedList::reversePrint()
{
    Node *temp = m_head;

    printf("Elements of linkedList are: ");

    _reversePrint(temp);
}

void LinkedList::_print(LinkedList::Node *temp)
{
    if( temp )
    {
        printf("%d-->",temp->data);

        _print(temp->link);
    }
}

void LinkedList::_reversePrint(LinkedList::Node *temp)
{
    if(temp)
    {
        _reversePrint(temp->link);

        printf("%d-->",temp->data);
    }
}

