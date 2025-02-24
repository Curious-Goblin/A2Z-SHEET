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
    void postorder(TreeNode *root, vector<int> &postOrder)
    {
        if (root == nullptr)
            return;
        postorder(root->left, postOrder);
        postorder(root->right, postOrder);
        postOrder.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrder;
        postorder(root, postOrder);
        return postOrder;
    }
};

int main()
{
    return 0;
}