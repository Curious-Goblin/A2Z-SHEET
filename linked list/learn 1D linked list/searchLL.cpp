#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

bool searchKey(int n, Node *head, int key)
{
    Node* current = head;
    while(current != nullptr){
        if(current -> data == key ) return true;
        current = current -> next;
    }
    return false;
}

int main()
{
    return 0;
}