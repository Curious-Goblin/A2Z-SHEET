#include "bits/stdc++.h"

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return (node);
}

class Solution
{
public:
    void create_tree(node *root0, vector<int> &vec)
    {
        queue<node *> q;
        q.push(root0);
        int i = 1;
        while (!q.empty() && i < vec.size())
        {
            node *current = q.front();
            q.pop();
            current->left = newNode(vec[i++]);
            q.push(current->left);
            if (i < vec.size())
            {
                current->right = newNode(vec[i++]);
                q.push(current->right);
            }
        }
    }
};

int main()
{
    return 0;
}