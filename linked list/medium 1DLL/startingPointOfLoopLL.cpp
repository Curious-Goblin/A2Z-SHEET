#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

int countNodesinLoop(ListNode *head)
{
    unordered_map<ListNode *, int> map;
    ListNode *current = head;
    int start = 0;
    int count = 0;
    while (current)
    {
        count++;
        map.insert({current, count});
        auto it = map.find(current->next);
        if (it != map.end())
        {
            return count - it->second + 1;
        }
        current = current->next;
    }
    return 0;
}

ListNode *detectCycle(ListNode *head)
{
    unordered_map<ListNode *, int> map;
    ListNode *current = head;
    int start = 0;
    int count = 0;
    while (current)
    {
        count++;
        map.insert({current, count});
        auto it = map.find(current->next);
        if (it != map.end())
        {
            return it->first;
        }
        current = current->next;
    }
    return nullptr;
}

int main()
{
    return 0;
}