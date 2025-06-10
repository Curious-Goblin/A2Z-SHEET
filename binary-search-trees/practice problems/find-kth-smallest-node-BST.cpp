#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    int kthSmallest(TreeNode *root, int k){
        int a = inorderTraversal(root, k);
        return a;
    }

    int inorderTraversal(TreeNode *root, int k)
    {
        vector<int> inOrder;
        if (root == nullptr)
            return -1;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->val);
                if(inOrder.size()==k){
                    return inOrder[inOrder.size()-1];
                }
                node = node->right;
            }
        }
        return inOrder[inOrder.size()-1];
    }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution sol;
    cout<<sol.kthSmallest(root, 1)<<endl;
    return 0;
}