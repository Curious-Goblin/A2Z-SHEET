#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node *bottom;
    Node(int val){
        data = val;
        next = nullptr;
        bottom = nullptr;
    }
};

class Solution{
    public:
    // this algorigthm is written for sorting the list in horizontal order and it complexity is o(N*2 + NlogN)
    // Node *findMiddle(Node *head){
    //     Node *slow=head,*fast = head, *prev = nullptr;
    //     while(fast && fast->next){
    //         prev = slow;
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     if(prev) prev->next = nullptr;
    //     return slow;
    // }
    // Node *mergeList(Node *leftHead, Node *rightHead){
    //     Node *head = new Node(0);
    //     Node *current = head;
    //     while(leftHead && rightHead){
    //         if(leftHead->data<rightHead->data){
    //             current->next = new Node(leftHead->data);
    //             leftHead = leftHead->next;
    //         }
    //         else{
    //             current->next = new Node(rightHead->data);
    //             rightHead = rightHead->next;
    //         }
    //         current = current->next;
    //     }
    //     if(leftHead) current->next = leftHead;
    //     if(rightHead) current->next = rightHead;
    //     return head->next;
    // }
    // Node *sortList(Node *head){
    //     if(!head || !head->next){
    //         return head;
    //     }
    //     Node *middle = findMiddle(head);
    //     Node *leftHead = sortList(head);
    //     Node *rightHead = sortList(middle);

    //     return mergeList(leftHead,rightHead);
    // }
    // Node *flatten(Node *root) {
    //     Node *current = root;
    //     while(current){
    //         Node *next = current->next;
    //         while(current->bottom){
    //             current->next = current->bottom;
    //             current = current->bottom;
    //         }
    //         current->next = next;
    //         current = current->next;
    //     }
    //     root = sortList(root);
    //     return root;
    // }

    // time complexity is O(n*2m) where m is the length of the sub list and space is 
    // recursive stack space used by recursion;
    Node *merge(Node *l1, Node *l2){
        Node *dummy = new Node(-1);
        Node *current = dummy;
        while(l1 && l2){
            if(l1->data < l2->data){
                current->bottom = l1;
                l1 = l1->bottom;
            }
            else{
                current->bottom = l2;
                l2 = l2->bottom;
            }
            current = current->bottom;
            current->next = nullptr;
        }
        if(l1) current->bottom = l1;
        if(l2) current->bottom = l2;

        return dummy->bottom;
    }

    Node *flatten(Node *root) {
        if(!root || !root->next){
            return root;
        }

        Node *newNode = flatten(root->next);

        return merge(root,newNode);
    }

    Node *constructLL(vector<vector<int>> &nums){
        Node *head = nullptr;
        Node *currentBottom = nullptr;
        for(int i=0;i<nums.size();i++){
            Node *rowHead = new Node(nums[i][0]);
            Node *columnHead = rowHead;
            for(int j=1;j<nums[i].size();j++){
                columnHead->bottom = new Node(nums[i][j]);
                columnHead = columnHead->bottom;
            }
            if(!head){
                head = rowHead;
            }
            else{
                currentBottom->next = rowHead;
            }
            currentBottom = rowHead;
        }
        return head;
    }
    void printLL(Node *head){
        while(head){
            cout<<head->data<<" ";
            head = head->bottom;
        }
    }
};

int main(){
    int n,m;
    cin>>n;
    vector<vector<int>> nums;
    for(int i=0;i<n;i++){
        cin>>m;
        vector<int> temp(m);
        for(int j=0;j<m;j++){
            cin>>temp[j];
        }
        nums.push_back(temp);
    }
    Solution s;
    Node *head = s.constructLL(nums);
    head = s.flatten(head);
    s.printLL(head);
}