#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    // This solution uses recursive DFS to build all root-to-leaf paths in the binary tree.
    // It appends each node’s value to a path string and adds it to the result upon reaching a leaf.
    // Time complexity is **O(N²)** in the worst case, and space complexity is **O(H)** due to recursion.

    // void paths(vector<string> &result, string currentPath, TreeNode *root){
    //     if(root == nullptr) return;

    //     currentPath += std::to_string(root->val);

    //     if(root->left == nullptr && root->right == nullptr){
    //         result.push_back(currentPath);
    //         return;
    //     }

    //     currentPath += "->";

    //     paths(result, currentPath, root->left);
    //     paths(result, currentPath, root->right);
    // }
    
    // vector<string> binaryTreePaths(TreeNode* root) {
    //     if(root == nullptr) return {};
    //     vector<string> result;
    //     string path1;
    //     paths(result, path1, root);
    //     return result;
    // }

    // Worst case time = O(number of leaves × path length) == O(n*2)
    vector<string> binaryTreePaths(TreeNode *root){
        if(root == nullptr) return {};

        stack<pair<TreeNode *, string>> st;
        vector<string> result;
        st.push({root, to_string(root->val)});
        while(!st.empty()){
            auto node = st.top().first;
            auto path = st.top().second;
            st.pop();
            if(node->left == nullptr && node->right == nullptr){
                result.push_back(path);
            }

            if(node->right){
                st.push({node->right, path + "->" + to_string(node->right->val)});
            }
            if(node->left){
                st.push({node->left, path + "->" + to_string(node->left->val)});
            }
        }
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);

    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}