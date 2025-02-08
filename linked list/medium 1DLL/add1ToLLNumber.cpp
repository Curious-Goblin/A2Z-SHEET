#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

Node *reverseLL(Node *head)
{
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
Node *addOne(Node *head)
{
    head = reverseLL(head);
    Node *current = head;
    int carry = 1;

    while (current)
    {
        current->data += carry;
        if (current->data == 10)
        {
            current->data = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
            break;
        }

        if (!current->next && carry)
        {
            current->next = new Node(1);
            carry = 0;
        }

        current = current->next;
    }

    return reverseLL(head);
}

int helper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    carry = 0;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addOneRecursive(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}

Node *createLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        current->next = new Node(nums[i]);
        current = current->next;
    }
    return head;
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
    head = addOneRecursive(head);
    printLL(head);
}