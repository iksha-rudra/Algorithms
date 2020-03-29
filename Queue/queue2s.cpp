#include "queue2s.h"
#include <stdio.h>

Queue2S::Queue2S()
{

}

void Queue2S::enqueue(int item)
{
    S1.push(item);
}

int Queue2S::dequeue()
{
    if( S2.isEmpty() )
    {
        if( S1.isEmpty() )
        {
            printf("Unterflow\n");
        }
        else
        {
            while(!S1.isEmpty())
            {
                int item = S1.pop();

                S2.push(item);
            }
        }
    }

    return S2.pop();
}

void Queue2S::display()
{
    S1.display();

    S2.displayReverse();
}

