#include "recursion.h"
#include <iostream>

Recursion::Recursion()
{

}

void Recursion::Hanoi(int n,char s,char d,char t)
{
    if(n > 0)
    {
        Hanoi(n-1,s,t,d);

        std::cout << "Move disk "<<n<<" from "<<s<<" to "<<d << std::endl;

        Hanoi(n-1,t,d,s);
    }
}

void Recursion::HanoiMoveDisk(int n)
{
    Hanoi(n,'a','c','b');
}
