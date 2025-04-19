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
        this->next = nullptr;
        this->next = nullptr;
    }
};

// vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
// {
//     Node *current = head;
//     vector<int> nums;
//     vector<pair<int, int>> result;
//     while (current)
//     {
//         nums.push_back(current->data);
//         current = current->next;
//     }
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             if ((nums[i] + nums[j]) == target)
//             {
//                 result.push_back({nums[i], nums[j]});
//             }
//         }
//     }
//     return result;
// }

// two pointer method (optimal) O(n/2)
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> result;
    if (!head)
        return result;
    Node *left = head;
    Node *right = head;
    while (right->next)
        right = right->next;

    while (left != right && left->prev != right)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return result;
}

Node *createDLL(vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

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

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Node *head = createDLL(nums);
    Node *current = head;
    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "(" << result[i].first << ", " << result[i].second << "), ";
    }
}