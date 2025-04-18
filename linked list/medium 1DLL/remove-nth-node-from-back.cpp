#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int data){
        val = data;
        next = nullptr;
    }
};

class Solution {
    public:
    ListNode *removeNthFromEnd(ListNode *head,int n){
        int count=0;
        ListNode *current = head;
        while(current){
            count++;
            current = current->next;
        }
        if((count - n) == 0){
            return head->next;
        }
        current = head;
        for(int i=1;i<(count - n);i++){
            current = current->next;
        }
        current->next = current->next->next;
        return head;
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
    void printLL(ListNode *head){
        ListNode *current = head;
        while(current){
            cout<<current->val<<" ";
            current = current->next;
        }
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    ListNode *head = s.constructLL(nums);
    head = s.removeNthFromEnd(head,k);
    s.printLL(head);
}