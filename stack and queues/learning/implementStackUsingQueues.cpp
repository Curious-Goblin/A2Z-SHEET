#include "bits/stdc++.h"

using namespace std;

class MyStack
{
public:
    queue<int> first, second;
    MyStack()
    {
    }

    void push(int x)
    {
        // second.push(x);
        // while (!first.empty())
        // {
        //     second.push(first.front());
        //     first.pop();
        // }
        // swap(first, second);

        // logic of implementing stack using only one queue
        
        first.push(x);
        int size = first.size();
        for(int i=0;i<size-1;i++){
            first.push(first.front());
            first.pop();
        }
    }

    int pop()
    {
        if (first.empty())
            return -1;
        int a = first.front();
        first.pop();
        return a;
    }

    int top()
    {
        if (first.empty())
            return -1;
        return first.front();
    }

    bool empty()
    {
        return first.empty();
    }
};