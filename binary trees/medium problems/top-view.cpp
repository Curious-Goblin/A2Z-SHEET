#include "bits/stdc++.h"

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution{
    public:
    vector<int> topView(Node *root){
        if(root==nullptr) return {};
        int hd=0;
        map<int, int> map;
        queue<pair<Node *, int>> qu;
        qu.push({root,0});
        while(!qu.empty()){
            auto node = qu.front();
            qu.pop();
            if(map.find(node.second)==map.end()){
                map.insert({node.second, node.first->data});
            };
            if(node.first->left) qu.push({node.first->left, node.second-1});
            if(node.first->right) qu.push({node.first->right, node.second+1});
        }
        vector<int> result;
        for(auto &it:map){
            result.push_back(it.second);
        }
        return result;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->left = new Node(6);
    root->left->right->right->left->right = new Node(7);
    root->left->right->right->left->right->right = new Node(8);
    root->left->right->right->left->right->right->left = new Node(9);
    root->left->right->right->left->right->right->right = new Node(10);
    root->left->right->right->left->right->right->right->right = new Node(11);
    Solution sol;
    vector<int> result = sol.topView(root);
    for(auto &value:result){
        cout<<value<<" ";
    }
    return 0;
}