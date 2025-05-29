#include "bits/stdc++.h"

using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    public:
    vector<vector<int>> allTraversals(TreeNode *root){
        if(root == nullptr) return {};
        vector<int> preorder, inorder, postorder;
        stack<pair<TreeNode *,int>> st;
        st.push({root, 1});
        while(!st.empty()){
            auto& val = st.top();
            if(val.second == 1){
                preorder.push_back(val.first->val);
                val.second++;
                if(val.first->left) st.push({val.first->left,1});
            }
            else if(val.second == 2){
                inorder.push_back(val.first->val);
                val.second++;
                if(val.first->right) st.push({val.first->right,1});
            }
            else{
                postorder.push_back(val.first->val);
                st.pop();
            }
        }
        vector<vector<int>> result;
        return {preorder, inorder, postorder};
    }
};

int main() {
    // Create this binary tree:
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> traversals = sol.allTraversals(root);

    vector<string> labels = {"Preorder", "Inorder", "Postorder"};
    for (int i = 0; i < traversals.size(); ++i) {
        cout << labels[i] << ": ";
        for (int val : traversals[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
