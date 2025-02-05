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
// bruteforce
// ListNode *middleNode(ListNode *head)
// {
//     int count=0;
//     ListNode *current = head;
//     while(current){
//         count++;
//         current=current->next;
//     }
//     current = head;
//     count = count/2 + 1;
//     while(current){
//         count--;
//         if(count == 0){
//             return current;
//         }
//         current = current->next;
//     }
//     return current;
// }

ListNode *middleNode(ListNode *head)
{
    int count=0;
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next != nullptr && fast != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    return 0;
}