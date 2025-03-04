#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // // Modified inorder function that populates both inOrder vector and nodeCounts map
    // int inorder(TreeNode *root, vector<int> &inOrder, unordered_map<int, pair<int, int>> &nodeCounts) {
    //     if (root == nullptr)
    //         return 0;

    //     int leftCount = inorder(root->left, inOrder, nodeCounts);
    //     inOrder.push_back(root->val);
    //     int rightCount = inorder(root->right, inOrder, nodeCounts);
    //     nodeCounts[root->val] = {leftCount, rightCount}; // Store left and right counts

    //     return leftCount + rightCount + 1; // Return total nodes in this subtree
    // }

    // // Function that returns both inorder traversal and node counts
    // pair<vector<int>, unordered_map<int, pair<int, int>>> inorderTraversal(TreeNode *root) {
    //     vector<int> inOrder;
    //     unordered_map<int, pair<int, int>> nodeCounts;
    //     inorder(root, inOrder, nodeCounts);
    //     return {inOrder, nodeCounts}; // Return both inorder traversal and node counts
    // }

    // // Function to compare two trees based on inorder traversal and node counts
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     auto [pTree, pCounts] = inorderTraversal(p); // Get inorder & nodeCounts for p
    //     auto [qTree, qCounts] = inorderTraversal(q); // Get inorder & nodeCounts for q

    //     // Compare inorder traversal
    //     if (pTree != qTree)
    //         return false;

    //     // Compare nodeCounts for each value in pTree (since pTree == qTree)
    //     for (int val : pTree) {
    //         if (pCounts[val] != qCounts[val]) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // optimal solution
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main()
{
    return 0;
}
