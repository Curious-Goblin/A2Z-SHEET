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
// using two stack
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrder;
        if (root == nullptr)
        {
            return postOrder;
        }
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty())
        {
            root = st1.top();
            st2.push(root);
            if (root->left != nullptr)
                st1.push(root->left);
            if (root->right != nullptr)
                st1.push(root->right);
        }
        while (!st2.empty())
        {
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }
        return postOrder;
    }

    /* using one stack
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postOrder;
        if (root == nullptr)
        {
            return postOrder;
        }
        stack<TreeNode *> st;
        TreeNode *current = root;
        TreeNode *temp;
        while (current != nullptr || !st.empty())
        {
            if (current != nullptr)
            {
                st.push(current);
                current = current->left;
            }
            else
            {
                temp = st.top()->right;
                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else
                {
                    current = temp;
                }
            }
        }

        return postOrder;
    }
    */
};

int main()
{
    return 0;
}