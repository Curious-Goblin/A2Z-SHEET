#include "bits/stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // bool findTarget(TreeNode* root, int k) {
    //     queue<TreeNode *> qu;
    //     qu.push(root);
    //     unordered_map<int, int> map;
    //     while(!qu.empty()){
    //         TreeNode *node = qu.front();
    //         qu.pop();
    //         if(map.find(k-node->val)!= map.end()){
    //             return true;
    //         }
    //         map[node->val] = 1;
    //         if(node->left) qu.push(node->left);
    //         if(node->right) qu.push(node->right);
    //     }   
    //     return false;
    // }

    void inorder(TreeNode *root, vector<int> &nums){
        if(root == nullptr) return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode *root, int k){
        vector<int> nums;
        inorder(root, nums);
        int left = 0, right = nums.size()-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == k) return true;
            else if(sum < k){
                left++;
            }
            else{
                right--;
            }
        }
        return false;
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(5);

    Solution sol;
    cout<<sol.findTarget(root, 11)<<endl;
    return 0;
}