#include "bits/stdc++.h"

using namespace std;

class MyQueue
{
public:
    stack<int> inStack, outStack;

    MyQueue() {}

    void push(int x)
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        if (outStack.empty())
            return -1;
        int a = outStack.top();
        outStack.pop();
        return a;
    }

    int peek()
    {
        if (outStack.empty())
        {
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.empty() ? -1 : outStack.top();
    }

    bool empty()
    {
        return outStack.empty() && inStack.empty();
    }
};