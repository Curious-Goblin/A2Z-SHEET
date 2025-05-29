#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),    right  (right) {}
};

class Solution{
    public:
    void inorder(TreeNode *root, vector<TreeNode *> &inOrder){
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (node != nullptr || !st.empty()){
            if(node){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inOrder.push_back(node);
                node = node->right;
            }
        }
    }
    vector<int> boundary(TreeNode *root){
        vector<int> leftHalf;
        vector<int> rightHalf;
        vector<int> leafs;
        vector<TreeNode *> inOrder;
        vector<int> result;
        result.push_back(root->val);
        inorder(root, inOrder);
        if(root->left){
            TreeNode *left = root->left;
            while(left && (left->right || left->left)){
                leftHalf.push_back(left->val);
                left = left->left;
            }
        }
        if(root->right){
            TreeNode *right = root->right;
            while(right && (right->right || right->left)){
                rightHalf.push_back(right->val);
                right = right->right;
            }
        }
        reverse(rightHalf.begin(), rightHalf.end());
        for(int i=0;i<inOrder.size();i++){
            if(!(inOrder[i]->left && inOrder[i]->right)){
                leafs.push_back(inOrder[i]->val);
            }
        }
        for(int i=0;i<leftHalf.size();i++){
            result.push_back(leftHalf[i]);
        }
        for(int i=0;i<leafs.size();i++){
            result.push_back(leafs[i]);
        }
        for(int i=0;i<rightHalf.size();i++){
            result.push_back(rightHalf[i]);
        }
        return result;
    }
};

int main(){
    //     1
    //    / \
    //   2   3
    //  / \   \
    // 4   5   6
    //    / \
    //   7   8

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<int> result = sol.boundary(root);

    for (auto& level : result) {
        cout<<level<<" ";
    }

    return 0;
}