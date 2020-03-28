#ifndef STACK_H
#define STACK_H

#define STACK_MAX 50

class Stack
{
public:
    Stack();

    void push(char item);

    char pop();

    char top();

    void display();

    bool isEmpty();

private:
    char m_Array[STACK_MAX];

    int m_top;
};

#endif // STACK_H
