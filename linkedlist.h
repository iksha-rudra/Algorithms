#ifndef LINKEDLIST_H
#define LINKEDLIST_H


class LinkedList
{
public:
    LinkedList();

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

    struct Node *m_head;

    void insertAtStart(int data);

    void insertAtEnd(int data);

    void insertAfterKey(int data, int key);

    void deleteHeadNode();

    void deleteEndNode();

    void deleteNodeWithKey(int key);

    void reverseR();

    void _reverseR(Node *prev, Node *cur);

    void reverse();

    void moveEndNodetoHead();

    void print();

    void reversePrint();

private:

    void _print(Node *temp);

    void _reversePrint(Node *temp);
};

#endif // LINKEDLIST_H
