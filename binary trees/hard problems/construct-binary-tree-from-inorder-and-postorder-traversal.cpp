#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* buildTreeRecursive(vector<int>& postorder, int postStart, int postEnd,
                                 vector<int>& inorder, int inStart, int inEnd,
                                 unordered_map<int, int>& map) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        Node* root = new Node(postorder[postEnd]);
        int inRoot = map[root->data];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeRecursive(postorder, postStart, postStart + numsLeft - 1,
                                        inorder, inStart, inRoot - 1, map);
        root->right = buildTreeRecursive(postorder, postStart + numsLeft, postEnd - 1,
                                         inorder, inRoot + 1, inEnd, map);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty() || postorder.size() != inorder.size()) {
            return nullptr;
        }

        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeRecursive(postorder, 0, postorder.size() - 1,
                                  inorder, 0, inorder.size() - 1, map);
    }

    vector<int> inorderTraversal(Node* root) {
        vector<int> inOrder;
        stack<Node*> st;
        Node* node = root;

        while (node || !st.empty()) {
            while (node) {
                st.push(node);
                node = node->left;
            }
            node = st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }

        return inOrder;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> postorder(n), inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    Solution sol;
    Node* root = sol.buildTree(inorder, postorder);
    vector<int> result = sol.inorderTraversal(root);
    for (int data : result) {
        cout << data << " ";
    }

    return 0;
}
