#include "bits/stdc++.h"

using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

DLLNode *reverseDLL(DLLNode *head)
{
    DLLNode *current = head;
    DLLNode *temp = nullptr;
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    if (temp)
        head = temp->prev;
    return head;
}

int main()
{
    return 0;
}