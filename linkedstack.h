#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H


class LinkedStack
{
public:
    LinkedStack();

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

    void push(int item);

    int pop();

    int top();

    bool isEmpty();

    void displayReverse();

private:

    Node *m_head;

    void _print(LinkedStack::Node *temp);

    void _reversePrint(LinkedStack::Node *temp);
};

#endif // LINKEDSTACK_H
