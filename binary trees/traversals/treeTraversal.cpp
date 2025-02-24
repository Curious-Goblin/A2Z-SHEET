#include "bits/stdc++.h"

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void inorder(TreeNode *root, vector<int> &inOrder) // left root right
{
    if (root == NULL)
        return;
    inorder(root->left, inOrder);
    inOrder.push_back(root->data);
    inorder(root->right, inOrder);
}

void preorder(TreeNode *root, vector<int> &preOrder) // root left right
{
    if (root == NULL)
        return;
    preOrder.push_back(root->data);
    preorder(root->left, preOrder);
    preorder(root->right, preOrder);
}

void postorder(TreeNode *root, vector<int> &postOrder) // left right root
{
    if (root == NULL)
        return;
    postorder(root->left, postOrder);
    postorder(root->right, postOrder);
    postOrder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> traversals;
    vector<int> inOrder, preOrder, postOrder;
    inorder(root, inOrder);
    preorder(root, preOrder);
    postorder(root, postOrder);
    traversals = {inOrder, preOrder, postOrder};
    return traversals;
}

int main()
{
    return 0;
}