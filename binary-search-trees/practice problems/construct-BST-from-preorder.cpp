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
    TreeNode *build(vector<int> &preorder, int &index, int bound){
        if(index == preorder.size() || preorder[index] > bound) return nullptr;

        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = build(preorder, index, root->val);
        root->right = build(preorder, index, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder){
        int index = 0;
        return build(preorder, index, INT_MAX);
    }
};

int main(){

    return 0;
}