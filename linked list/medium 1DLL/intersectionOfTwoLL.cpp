#include "bits/stdc++.h"

using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA;
    ListNode *b = headB;
    if (!a || !b)
        return nullptr;
    while (a != b)
    {
        a = (a == nullptr) ? headB : a->next;
        b = (b == nullptr) ? headA : b->next;
        if (a == b)
            return b;
    }
    return a;
}

int main()
{
    return 0;
}