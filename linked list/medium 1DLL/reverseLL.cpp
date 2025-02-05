#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *current = head;
    ListNode *temp = head;
    while(temp){
        if(current == head){
            temp= current->next;
            current = current->next;
            current->next=nullptr;
            continue;
        }
        temp = current->next;
    }
}

int main()
{
    return 0;
}