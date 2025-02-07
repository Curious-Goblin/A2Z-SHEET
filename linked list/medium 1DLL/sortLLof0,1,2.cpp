#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

Node *segregate(Node *head) {
    if (!head) return nullptr;

    Node *Node0 = new Node(-1), *head0 = Node0;
    Node *Node1 = new Node(-1), *head1 = Node1;
    Node *Node2 = new Node(-1), *head2 = Node2;

    Node *current = head;

    while (current) {
        if (current->data == 0) {
            Node0->next = current;
            Node0 = current;
        } else if (current->data == 1) {
            Node1->next = current;
            Node1 = current;
        } else if (current->data == 2) {
            Node2->next = current;
            Node2 = current;
        }
        current = current->next;
    }

    Node0->next = (head1->next) ? head1->next : head2->next;
    Node1->next = head2->next;
    Node2->next = nullptr; 

    Node *newHead = head0->next;
    delete head0;
    delete head1;
    delete head2;

    return newHead;
}

Node *createLL(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;
    Node *head = new Node(nums[0]);
    Node *current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        current->next = new Node(nums[i]);
        current = current->next;
    }
    return head;
}

void printLL(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
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
    Node *head = createLL(nums);
    Node *result = segregate(head);
    printLL(result);
}