#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> inorder;
        TreeNode *curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }

                if(prev->right == nullptr){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(45);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}