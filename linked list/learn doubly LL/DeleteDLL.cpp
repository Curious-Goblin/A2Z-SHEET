#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *deleteNode(Node *head, int x)
{
    if (head == nullptr)
        return nullptr;

    Node *current = head;

    for (int i = 1; i < x && current != nullptr; i++)
    {
        current = current->next;
    }

    if (current == nullptr)
        return head;

    if (current == head)
    {
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete current;
        return head;
    }

    if (current->next == nullptr)
    {
        current->prev->next = nullptr;
        delete current;
        return head;
    }

    Node *previousNode = current->prev;
    Node *nextNode = current->next;
    previousNode->next = nextNode;
    nextNode->prev = previousNode;

    delete current;
    return head;
}
