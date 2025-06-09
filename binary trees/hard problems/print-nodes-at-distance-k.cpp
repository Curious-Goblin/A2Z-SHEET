#include "bits/stdc++.h"

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
    public:
    void mapParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *par = nullptr){
        if(!root) return;
        if(par) parent[root] = par;
        mapParents(root->left, parent, root);
        mapParents(root->right, parent, root);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k){
        vector<int> result;

        unordered_map<TreeNode *, TreeNode *> parent;
        mapParents(root, parent); 

        queue<TreeNode *> qu;
        qu.push(target);

        unordered_set<TreeNode *> visited;
        visited.insert(target);

        int dist = 0;

        while(!qu.empty()){
            int size = qu.size();
            if(dist == k) break;
            for(int i = 0; i < size; i++){
                TreeNode *curr = qu.front();
                qu.pop();
                if(curr->left && visited.count(curr->left)==0){
                    visited.insert(curr->left);
                    qu.push(curr->left);
                }
                if(curr->right && visited.count(curr->right) == 0){
                    visited.insert(curr->right);
                    qu.push(curr->right);
                }
                if(parent.count(curr) && visited.count(parent[curr]) == 0){
                    visited.insert(parent[curr]);
                    qu.push(parent[curr]);
                }
            }
            dist++;
        }
        while(!qu.empty()){
            result.push_back(qu.front()->val);
            qu.pop();
        }
        return result;
    }
};

int main(){
    TreeNode *root = new TreeNode(35);
    root->left = new TreeNode(20);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(1);

    Solution sol;
    vector<int> result = sol.distanceK(root, root->left, 2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}