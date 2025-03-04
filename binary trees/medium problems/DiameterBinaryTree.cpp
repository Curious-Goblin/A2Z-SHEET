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
    int maxDepth(TreeNode *root, int &d)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left, d);
        int rh = maxDepth(root->right, d);
        d = max(d, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d=0;
        maxDepth(root, d);
        return d;
    }
};

int main()
{
    return 0;
}