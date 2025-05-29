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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> qu;
        vector<vector<int>> result;
        if(root == nullptr) return result;
        qu.push(root);
        bool leftToRight = true;
        while(!qu.empty()){
            int n = qu.size(),index=0;
            vector<int> temp(n);
            TreeNode *var;
            for(int i=0;i<n;i++){
                var = qu.front();
                qu.pop();
                index = leftToRight ? i : n-i-1;
                temp[index] = var->val;
                if(var->left) qu.push(var->left);
                if(var->right) qu.push(var->right);
            }
            if(!temp.empty()){
                result.push_back(temp);
            }
            leftToRight = !leftToRight;
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    for (auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}