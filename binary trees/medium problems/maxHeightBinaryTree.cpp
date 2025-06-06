#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }

    // iterative solution

    // int maxDepth(TreeNode *root)
    // {
    //     if (root == nullptr) return 0;

    //     queue<TreeNode *> q;
    //     q.push(root);
    //     int depth = 0;

    //     while (!q.empty())
    //     {
    //         int size = q.size();
    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = q.front();
    //             q.pop();
    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);
    //         }
    //         depth++;
    //     }
    //     return depth;
    // }
};

int main()
{
    return 0;
}