#ifndef RECURSION_H
#define RECURSION_H


class Recursion
{
public:
    Recursion();

    static void Hanoi(int n, char s, char d, char t);

    static void HanoiMoveDisk(int n);
};

#endif // RECURSION_H
