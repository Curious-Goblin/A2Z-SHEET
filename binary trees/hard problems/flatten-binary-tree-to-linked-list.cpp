#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    void flatten(TreeNode *root){
        TreeNode *curr = root;
        while(curr != nullptr){
            if(curr->left){
                TreeNode *prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }

    void printTree(TreeNode *root){
        while(root!=nullptr){
            cout<<root->val<<" ";
            root = root->right;
        }
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
    sol.flatten(root);
    sol.printTree(root);
    return 0;
}