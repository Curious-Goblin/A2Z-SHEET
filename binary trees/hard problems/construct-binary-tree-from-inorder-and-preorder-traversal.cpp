#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    TreeNode *buildTreeRecursive(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &map){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preStart]);

        int inRoot = map[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeRecursive(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, map);
        root->right = buildTreeRecursive(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, map);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        TreeNode *root = buildTreeRecursive(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, map);
        return root;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inOrder;
        if (root == nullptr)
            return inOrder;
        stack<TreeNode *> st;
        TreeNode *node = root;
        while (true)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if (st.empty())
                    break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->val);
                node = node->right;
            }
        }
        return inOrder;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> inorder(n), preorder(n);
    for(int i=0;i<n;i++){
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++){
        cin>>inorder[i];
    }
    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);
    vector<int> result = sol.inorderTraversal(root);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}