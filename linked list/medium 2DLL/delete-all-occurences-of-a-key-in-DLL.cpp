#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class Solution{
    public:
    // O(N)
    void deleteAllOccurOfX(Node **head_ref, int x){
        Node *current = (*head_ref);
        while(current){
            Node *next = current->next;
            if(current->data == x){
                if(current == (*head_ref)){
                    (*head_ref) = (*head_ref)->next;
                    if(*head_ref){
                        (*head_ref)->prev = nullptr;
                    }
                }
                else {
                    // if prev exist then we can access its next element and assign it to
                    // next element of current;
                    if(current->prev){
                        current->prev->next = current->next;
                    }
                    if(current->next){
                        current->next->prev = current->prev;
                    }
                }
                delete current;
            }
            current = next;
        }
    }
    Node *constructDLL(vector<int> &nums){
        Node *head = new Node(nums[0]);
        Node *current = head;
        for(int i=0;i<nums.size();i++){
            Node *newNode = new Node(nums[i]);
            current->next = newNode;
            newNode->prev = current;
            current = newNode;
        }
        return head;
    }
    void printDLL(Node *head){
        while(head){
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    Node *head = s.constructDLL(nums);
    s.deleteAllOccurOfX(&head,x);
    s.printDLL(head);
}