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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *curr = root, *prev = nullptr;
        if(!root) return new TreeNode(val);
        while (curr)
        {
            prev = curr;
            if (val > curr->val)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (val > prev->val)
        {
            prev->right = new TreeNode(val);
        }
        else
        {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};

int main()
{
    return 0;
}