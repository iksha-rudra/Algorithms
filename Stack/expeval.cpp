#include "expeval.h"
#include <string.h>
#include <stdio.h>

ExpEval::ExpEval()
{

}

int ExpEval::getPriority(char c)
{
    int priority = -1;

    if( c == '*' || c == '/' )
    {
        priority = 2;
    }

    if( c == '+' || c == '-' )
    {
        priority = 1;
    }

    return priority;
}

bool ExpEval::isOperator(char c)
{
    if( c == '*' ||
        c == '/' ||
        c == '+' ||
        c == '-' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ExpEval::isLP(char c)
{
    if( c == '(')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ExpEval::isRP(char c)
{
    if( c == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char *ExpEval::postFix(char *inFixStr)
{
    int size = strlen(inFixStr);

    char *postFixStr = new char[size];

    int i;

    int j;

    for(i = 0, j = 0; i < size; i++)
    {
        char c = inFixStr[i];

        if( isLP(c) )
        {
            S.push(c);
        }

        else if(  !isOperator(c) && !isRP(c) )
        {
            postFixStr[j++] = c;
        }

        else if( isRP(c) )
        {
            char p;

            while( 1 )
            {
                p = S.pop();

                if( !isLP(p) )
                {
                    postFixStr[j++] = p;
                }
                else
                {
                    break;
                }
            }
        }
        else    //operator or left paranthesis
        {
            while( 1 )
            {
                bool empty = S.isEmpty();

                if( empty )
                {
                    break;
                }

                bool lp = isLP(S.top());

                if( lp )
                {
                    break;
                }

                int priorityS = getPriority(S.top());

                int priorityI = getPriority(c);

                if( priorityI <= priorityS )
                {
                    char p = S.pop();

                    postFixStr[j++] = p;
                }
                else
                {
                    break;
                }
            }

            S.push(c);
        }
    }

    while(!S.isEmpty())
    {
        postFixStr[j++] = S.pop();;
    }

    postFixStr[j] = '\0';

    return postFixStr;
}

int ExpEval::evaluate(char *inFixStr)
{
    char *postFixStr = postFix(inFixStr);

    int size = strlen(postFixStr);

    for(int i = 0; i < size; i++)
    {
        char c = postFixStr[i];

        if( !isOperator(c) )
        {
            SInt.push(c-'0');
        }
        else
        {
            int op2 = SInt.pop();

            int op1 = SInt.pop();

            if( c == '*')
            {
                SInt.push(op1*op2);
            }
            else if(c =='/')
            {
                SInt.push(op1/op2);
            }
            else if(c == '+')
            {
                SInt.push(op1+op2);
            }
            else if(c == '-')
            {
                SInt.push(op1-op2);
            }
        }
    }

    int result = SInt.pop();

    return result;
}

