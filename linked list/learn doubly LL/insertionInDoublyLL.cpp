#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node *addNode(Node *head, int pos, int data)
{
    Node *current = head;
    if (pos == 0)
        return new Node(data);
    while (pos != 0)
    {
        pos--;
        current = current->next;
    }
    Node *newNode = new Node(data);
    newNode->next = current->next;
    if(newNode->next != nullptr) newNode->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return head;
}

int main()
{
    return 0;
}