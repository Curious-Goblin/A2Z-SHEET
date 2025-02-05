#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

int getCount(struct Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    return 0;
}