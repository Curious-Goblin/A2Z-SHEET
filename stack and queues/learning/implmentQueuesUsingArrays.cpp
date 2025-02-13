#include "bits/stdc++.h"

using namespace std;

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};

void MyQueue ::push(int x)
{
    arr[rear] = x;
    rear++;
}

int MyQueue ::pop()
{
    if (rear == 0 || front == rear)
    {
        return -1;
    }
    int a = arr[front];
    arr[front] = -1;
    front++;
    return a;
}