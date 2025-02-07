#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val)
    {
        val = val;
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

bool isPalindrome(ListNode *head)
{
    map<int, int> map;
    ListNode *current = head;
    int count = 0;
    while (current)
    {
        count++;
        map.insert({count, current->val});
        current = current->next;
    }
    auto first = map.begin();
    auto last = map.end();
    --last;
    while (first->first < last->first)
    {
        if (first->second == last->second)
        {
            ++first;
            --last;
        }
        else
        {
            return false;
        }
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