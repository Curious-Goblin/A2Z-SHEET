#include "bits/stdc++.h"

using namespace std;

struct StackNode
{
    int data;
    StackNode *next;

    StackNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        int result = top->data;
        top = top->next;
        return result;
    }

    MyStack() { top = NULL; }
};

int main()
{
    int n, a, b;
    cin >> n;
    vector<vector<int>> arg;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            arg.push_back({a, b});
        }
        else
        {
            arg.push_back({a});
        }
    }
    MyStack staack;
    for (int i = 0; i < n; i++)
    {
        if (arg[i][0] == 1)
        {
            staack.push(arg[i][1]);
        }
        else if (arg[i][0] == 2)
        {
            cout << staack.pop() << " ";
        }
    }
}