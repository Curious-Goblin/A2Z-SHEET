#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

ListNode *createLL(vector<int> &nums)
{
    ListNode *head = new ListNode(nums[0]);
    ListNode *current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}
// O(NlogN + N/2)
// bool isPalindrome(ListNode *head)
// {
//     map<int, int> map;
//     ListNode *current = head;
//     int count = 0;
//     while (current)
//     {
//         count++;
//         map.insert({count, current->val});
//         current = current->next;
//     }
//     auto first = map.begin();
//     auto last = map.end();
//     --last;
//     while (first->first < last->first)
//     {
//         if (first->second == last->second)
//         {
//             ++first;
//             --last;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return true;
// }

// O(n/2 + n/2 +n/2) constant space
bool isPalindrome(ListNode *head)
{
    ListNode *slow=head,*fast=head;
    ListNode *current = head;

    while(fast && fast->next){
        slow = slow->next, fast = fast->next->next;
    }

    ListNode *start = slow;

    if(fast!= nullptr){
        start=start->next;
    }

    current = start;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    ListNode *head1 = prev;
    current = head;

    while(head1){
        if(current->val != head1->val){
            return false;
        }
        current = current->next;
        head1 = head1->next;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ListNode *head = createLL(nums);
    bool result = isPalindrome(head);
    cout << result;
    return 0;
}