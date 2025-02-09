#include "bits/stdc++.h"

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *createDLL(vector<int> &nums)
{
    Node *head = new Node(nums[0]);
    Node *current = head;
    for (int i = 1; i < nums.size(); i++)
    {
        Node *newNode = new Node(nums[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

Node *removeDuplicates(struct Node *head)
{
    if (!head || !head->next)
        return head;
    Node *current = head;
    Node *newNode = NULL;
    Node *prevNode = current;
    while (current && current->next)
    {
        newNode = current->next;
        if (newNode->data == current->data)
        {
            current = current->next;
        }
        else if(newNode->data != current->data){
            prevNode->next = newNode;
            newNode->prev = prevNode;
            prevNode = newNode;
            current = current->next;
        }
    }
    if(current->prev->data == current->data){
        current->prev->next = NULL;
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
    Node *head = createDLL(nums);
    head = removeDuplicates(head);
    printDLL(head);
    return 0;
}