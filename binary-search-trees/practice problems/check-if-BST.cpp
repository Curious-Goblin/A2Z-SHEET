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
    bool recursive(TreeNode *root, long long min, long long max){
        if(!root) return true;
        if(root->val <= min || root->val >= max){
            return false;
        }
        return recursive(root->left, min, root->val) && recursive(root->right, root->val, max);
    }
    bool isValidBST(TreeNode *root){
        if(!root) return true;
        return recursive(root, LLONG_MIN, LLONG_MAX);
    }
};

int main(){
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(3);
    Solution sol;
    cout<<sol.isValidBST(root)<<endl;
    return 0;
}
