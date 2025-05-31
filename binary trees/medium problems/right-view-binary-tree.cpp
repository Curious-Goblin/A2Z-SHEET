#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> result;
        queue<TreeNode *> qu;
        qu.push(root);
        result.push_back(root->val);
        TreeNode *node, *lastNode;
        while(!qu.empty()){
            int n = qu.size();
            lastNode = nullptr;
            for(int i=0;i<n;i++){
                node = qu.front();
                qu.pop();
                if(node->left) {
                    qu.push(node->left);
                    lastNode = node->left;
                }
                if(node->right) {
                    qu.push(node->right);
                    lastNode = node->right;
                }
            }
            if(lastNode) result.push_back(lastNode->val);
        }
        return result;
    }
};

int main(){

/*
            1
           / \   
          2   3
         /
        4
       / \
      5   6
     /
    7
*/ 

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    root->left->left->right = new TreeNode(6);
    root->left->left->left->left = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.rightSideView(root);
    for(auto &val:result){
        cout<<val<<" ";
    }
    return 0;
}