#ifndef EXPEVAL_H
#define EXPEVAL_H

#include "stack.h"
#include "linkedstack.h"

class ExpEval
{

public:

    ExpEval();

    char *postFix(char *inFixStr);

    int evaluate(char *inFixStr);

    bool isOperator(char c);

    bool isLP(char c);

    bool isRP(char c);

    int getPriority(char c);
private:

    Stack S;

    LinkedStack SInt;
};

#endif // EXPEVAL_H
