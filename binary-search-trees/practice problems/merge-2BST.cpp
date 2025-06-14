#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        if(node->right){
            pushLeft(node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushLeft(TreeNode *node){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }
};


int main(){

    return 0;
}