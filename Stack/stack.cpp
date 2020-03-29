#include "stack.h"
#include <stdio.h>
#include "General/utility.h"

Stack::Stack():
    m_top(-1)
{

}

void Stack::push(char item)
{
    if( m_top == STACK_MAX-1 )
    {
        printf("Overflow\n");
    }
    else
    {
        m_top = m_top + 1;

        m_Array[m_top] = item;
    }
}

char Stack::pop()
{
    char item=' ';

    if( m_top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        item = m_Array[m_top];

        m_top = m_top - 1;
    }

    return item;
}

char Stack::top()
{
    return m_Array[m_top];
}

void Stack::display()
{
    Utility::display(m_Array, m_top+1);
}

bool Stack::isEmpty()
{
    bool empty = false;

    if( m_top == -1 )
    {
        empty = true;
    }

    return empty;
}

