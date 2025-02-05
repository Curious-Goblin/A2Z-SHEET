#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *current = head;
    for (int i = 1; i < arr.size(); i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return 0;
}