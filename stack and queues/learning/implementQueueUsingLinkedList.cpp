#include "bits/stdc++.h"

using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue
{
    int data;
    QueueNode *front, *rear;
    void push(int);
    void printLL();
    int pop();
    MyQueue() { front = rear = NULL; }
};

void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int MyQueue ::pop()
{
    if (front == NULL)
    {
        return -1;
    }
    int result = front->data;
    front = front->next;
    return result;
}

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
    MyQueue queuee;
    for (int i = 0; i < n; i++)
    {
        if (arg[i][0] == 1)
        {
            queuee.push(arg[i][1]);
        }
        else if (arg[i][0] == 2)
        {
            cout << queuee.pop() << " ";
        }
    }
}