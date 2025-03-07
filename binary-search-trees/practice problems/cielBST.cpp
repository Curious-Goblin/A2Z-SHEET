#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int result = 0;
    while (root)
    {
        if (input > root->data)
        {
            root = root->right;
        }
        else if (input < root->data)
        {
            result = root->data;
            root = root->left;
        }
        else {
            return root->data;
        }
    }
    return result;
}

int main()
{
    return 0;
}