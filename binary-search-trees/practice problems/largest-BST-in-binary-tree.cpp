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
    struct info{
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    int maxsize = 0;

    info dfs(Node *root){
        if(!root) return {true, 0, INT_MAX, INT_MIN};

        info left = dfs(root->left);
        info right = dfs(root->right);

        if(left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal){
            int currsize = left.size + right.size + 1;
            maxsize = max(currsize, maxsize);

            return {true, currsize, min(root->data, left.minVal), max(root->data, right.maxVal)};
        }

        return {false, 0, 0, 0};
    }
    int largestBst(Node *root){
        maxsize = 0;
        dfs(root);
        return maxsize;
    }
};

int main(){
    return 0;
}