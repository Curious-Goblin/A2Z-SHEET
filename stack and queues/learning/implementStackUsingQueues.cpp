#include "bits/stdc++.h"

using namespace std;

class MyStack
{
public:
    queue<int> first,second;
    MyStack()
    {
        while(!first.empty()) first.pop();
        while(!second.empty()) second.pop();
    }

    void push(int x)
    {
        first.push(x);
        if(second.size()==1){
            second.pop();
            second.push(x);
        }
        second.push(x);
    }

    int pop()
    {
        int a = second.front();
        first.pop();
        second.pop();
        return a;
    }

    int top()
    {
        return second.front();
    }

    bool empty()
    {
        return first.empty();
    }
};