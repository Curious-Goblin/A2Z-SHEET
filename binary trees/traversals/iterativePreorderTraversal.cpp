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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preOrder;
        if (root == nullptr)
            return preOrder;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            preOrder.push_back(st.top()->val);
            root = st.top();
            st.pop();
            if (root->right != nullptr)
                st.push(root->right);
            if (root->left != nullptr)
                st.push(root->left);
        }
        return preOrder;
    }
};

int main()
{
    return 0;
}