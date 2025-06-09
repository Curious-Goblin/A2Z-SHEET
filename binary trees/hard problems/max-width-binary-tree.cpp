#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, unsigned long long>> qu;
        qu.push({root, 1});
        int width = 0;

        while (!qu.empty()) {
            int n = qu.size();
            unsigned long long first_index = 0, last_index = 0;

            for (int i = 0; i < n; i++) {
                auto node = qu.front().first;
                unsigned long long index = qu.front().second;
                qu.pop();

                if (i == 0) first_index = index;
                if (i == n - 1) last_index = index;

                if (node->left) {
                    qu.push({node->left, 2 * index});
                }
                if (node->right) {
                    qu.push({node->right, 2 * index + 1});
                }
            }

            width = max(width, int(last_index - first_index + 1));
        }

        return width;
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

    Soluiton sol;
    cout<<sol.widthOfBinaryTree(root)<<endl;
    return 0;
}
