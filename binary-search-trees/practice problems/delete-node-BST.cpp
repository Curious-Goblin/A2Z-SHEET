#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(key < root->val) root->left = deleteNode(root->left, key);

        else if(key > root->val) root->right = deleteNode(root->right, key);

        else {
            if(!root->left) return root->right;
            if(!root->right) return root->left;

            TreeNode *succesor = getMin(root->right);
            root->val = succesor->val;
            root->right = deleteNode(root->right, succesor->val);
        }
        return root;
    }

    TreeNode* getMin(TreeNode *node){
        while(node->left != nullptr){
            node = node->left;
        }
        return node;
    }
};

int main(){
    return 0;
}