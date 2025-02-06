#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

bool hasCycle(ListNode *head)
{
    ListNode *slow=head,*fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}