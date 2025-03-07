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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *lastRoot = root;
        while (root)
        {
            if (val == root->val)
            {
                return lastRoot;
            }
            if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            lastRoot = root;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}