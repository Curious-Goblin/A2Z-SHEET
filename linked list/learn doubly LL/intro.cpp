#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};

Node *constructDLL(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}

int main()
{
    return 0;
}