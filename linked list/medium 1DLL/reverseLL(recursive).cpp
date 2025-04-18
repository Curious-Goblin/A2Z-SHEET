#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int data;
    ListNode *next;
    ListNode(int val){
        data = val;
        next = nullptr;
    }
};

ListNode *reverseListRecursive(ListNode *head){
    if(!head || !head->next) return head;

    ListNode *newHead = reverseListRecursive(head->next);

    // here head->next represents the next node and then the order between the nodes is reversed like head is at 1, 1->2->null it will be changed to 2->1->null;
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

ListNode *constructLL(vector<int> &arr){
    ListNode *head = new ListNode(arr[0]);
    ListNode *current = head;
    for(int i=1;i<arr.size();i++){
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ListNode *head = constructLL(arr);
    ListNode *newHead = reverseListRecursive(head);
    ListNode *current = newHead;
    while(current){
        cout<<current->data<<" ";
        current = current->next;
    }
}