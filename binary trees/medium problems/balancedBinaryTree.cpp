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
    // int maxDepth(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return 0;
    //     int lh = maxDepth(root->left);
    //     int rh = maxDepth(root->right);
    //     return 1 + max(lh, rh);
    // }
    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return true;
    //     TreeNode *left = root->left;
    //     bool l = isBalanced(left);
    //     TreeNode *right = root->right;
    //     bool r = isBalanced(right);
    //     int hl = maxDepth(left);
    //     int hr = maxDepth(right);
    //     if (abs(hr - hl) <= 1 && l && r)
    //         return true;
    //     return false;
    // }

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        if (lh == -1 || rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        int result = maxDepth(root);
        if (result == -1)
            return false;
        return true;
    }
};

int main()
{
    return 0;
}