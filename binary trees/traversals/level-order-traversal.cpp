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

class Solution {
public:
// this was my brute force sotuion which is correct and works but it is a bit complex while 
// using stack the other one will be using queue which will make is way simpler
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     stack<TreeNode *> st;
    //     vector<vector<int>> result;
    //     if(root == nullptr) return result;
    //     result.push_back({root->val});
    //     st.push(root);
    //     while(!st.empty()){
    //         int n = st.size();
    //         vector<int> temp;
    //         stack<TreeNode *> st1;
    //         TreeNode *var;
    //         for(int i=0;i<n;i++){
    //             var = st.top();
    //             st.pop();
    //             if(var->left!=nullptr){
    //                 temp.push_back(var->left->val);
    //                 st1.push(var->left);
    //             }
    //             if(var->right!=nullptr){
    //                 temp.push_back(var->right->val);
    //                 st1.push(var->right);
    //             }
    //         }
    //         if(!temp.empty()){
    //             result.push_back(temp);
    //         }
    //         while(!st1.empty()){
    //             st.push(st1.top());
    //             st1.pop();
    //         }
    //     }
    //     return result;
    // }

    // now this one uses only a single queue and in this way the time complexity also gets reduced.\
    // O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> qu;
        vector<vector<int>> result;
        if(root == nullptr) return result;
        qu.push(root);
        while(!qu.empty()){
            int n = qu.size();
            vector<int> temp;
            TreeNode *var;
            for(int i=0;i<n;i++){
                var = qu.front();
                qu.pop();
                temp.push_back(var->val);
                if(var->left) qu.push(var->left);
                if(var->right) qu.push(var->right);
            }
            if(!temp.empty()){
                result.push_back(temp);
            }
        }
        return result;
    }
};

int main(){
    //       1
    //      / \
    //     2   3
    //        / \
    //       6   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    for (auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}