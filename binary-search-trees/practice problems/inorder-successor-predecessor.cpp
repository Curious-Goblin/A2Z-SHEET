#include "bits/stdc++.h"

using namespace std;

class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
    void find(Node *root, int key, Node* &pre, Node* &suc){
        if(root == NULL) return;
        if(root->data < key){
            pre = root;
            find(root->right, key, pre, suc);
        }
        else if(root->data > key){
            suc = root;
            find(root->left, key, pre, suc);
        }
        else{
            if(root->left){
                Node *temp = root->left;
                while(temp->right) temp = temp->right;
                pre = temp;
            }
            if(root->right){
                Node *temp = root->right;
                while(temp->left) temp = temp->left;
                suc = temp;
            }
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        if(root == NULL) return {};
        vector<Node *> result(2);
        Node *pre = NULL, *suc = NULL;
        find(root, key, pre, suc);
        result[0] = pre;
        result[1] = suc;
        return result;
    } 
};

int main(){
    return 0;
}