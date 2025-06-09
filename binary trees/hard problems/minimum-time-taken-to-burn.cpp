#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    void mapParent(Node *root, unordered_map<Node *, Node *> &parent, int target, Node *&tar, Node *par = nullptr){
        if(!root) return;
        if(par) parent[root] = par;
        if(root->data == target) tar = root;
        mapParent(root->left, parent, target, tar, root);
        mapParent(root->right, parent, target, tar, root);
    }
    int minTime(Node *root, int target){
        int time = 0;
        unordered_map<Node *, Node *> parent;
        Node *tar = nullptr;
        mapParent(root, parent, target, tar);
        queue<Node *> qu;
        qu.push(tar);

        unordered_set<Node *> visited;
        visited.insert(tar);

        while(!qu.empty()){
            int size = qu.size();
            for(int i=0;i<size;i++){
                Node *curr = qu.front();
                qu.pop();
                if(curr->left && visited.count(curr->left) == 0 ){
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
            time++;
        }
        return time-1;
    }
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(45);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);
    root->left->right->right = new Node(7);

    Solution sol;
    cout<<sol.minTime(root, 7)<<endl;
    return 0;
}