#include "bits/stdc++.h"

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node)
{
    ListNode *nextELement = node->next;
    node->val = nextELement->val;
    node->next = nextELement->next;
    delete nextELement;
}

int main()
{
    return 0;
}