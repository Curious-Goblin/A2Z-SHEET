#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *insertAtEnd(Node *head, int x)
{
    if (head == nullptr)
    {
        return new Node(x);
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new Node(x);
    return head;
}

int main()
{
    return 0;
}