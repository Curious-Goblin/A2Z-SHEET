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
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    // this method uses extra vector and queue spaces which is not efficient
    // void recoverTree(TreeNode *root){
    //     vector<int> inOrder;
    //     inorder(root, inOrder);
    //     vector<int> nums = inOrder;
    //     sort(inOrder.begin(),inOrder.end());
    //     int a=-1, b=-1;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]!= inOrder[i]){
    //             if(a==-1){
    //                 a = nums[i];
    //             }
    //             else{
    //                 b = nums[i];
    //             }
    //         }
    //     }
    //     fixTree(root, a, b);
    // }
    void inorder2(TreeNode *root, vector<int> &inOrder){
        if(root == nullptr) return;
        inorder2(root->left, inOrder);
        inOrder.push_back(root->val);
        inorder2(root->right, inOrder);
    }
    // void fixTree(TreeNode *root, int a, int b){
    //     if(!root) return;
    //     if(root->val == a) root->val = b;
    //     else if(root->val == b) root->val = a;
    //     fixTree(root->left, a, b);
    //     fixTree(root->right, a, b);
    // }

    void recoverTree(TreeNode *root){
        inorder(root);
        if(first && second){
            swap(first->val, second->val);
        }
    }

    void inorder(TreeNode *root){
        if(!root) return;

        inorder(root->left);

        if(prev && prev->val > root->val){
            if(!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }
};

int main(){
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    vector<int> inorder;

    Solution sol;
    sol.recoverTree(root);
    sol.inorder2(root, inorder);
    for(int i=0;i<inorder.size();i++){
        cout<<inorder[i]<<" ";
    }
    cout<<endl;

    return 0;
}