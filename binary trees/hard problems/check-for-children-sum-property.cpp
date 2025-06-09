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
    int isSumProperty(Node *root){
        if(root == nullptr || (root->left == nullptr &&  root->right == nullptr)){
            return 1;
        }
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        if(sum == root->data  && isSumProperty(root->left) && isSumProperty(root->right)){
            return 1;
        }
        return 0;
    }
};

int main(){
    Node *root = new Node(35);
    root->left = new Node(20);
    root->right = new Node(15);
    root->left->left = new Node(15);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    Solution sol;
    cout<<sol.isSumProperty(root)<<endl;
    return 0;
}