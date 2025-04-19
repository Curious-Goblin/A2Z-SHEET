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

// this approach will work total for Na + Nb iterations, total length of both the linked lists
// and this will not get into an infinite loop because after iteration total length of ll they
// will meet at the nullptr stage and the while loop will terminate.
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