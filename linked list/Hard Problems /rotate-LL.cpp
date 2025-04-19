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

class Solution{
    public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode *current = head;
        int count=1;
        while(current->next){
            count++;
            current = current->next;
        }
        k=k%count;
        if(k==0) return head;
        current->next = head;
        current = head;
        k = count-k;
        while(k>1){
            current = current->next;
            k--;
        }
        head = current->next;
        current->next = nullptr;
        return head;
    }
    ListNode *constructLL(vector<int> &nums){
        ListNode *head = new ListNode(nums[0]);
        ListNode *current = head;
        for(int i=1;i<nums.size();i++){
            current ->next = new ListNode(nums[i]);
            current = current->next;
        }
        return head;
    }
    void printLL(ListNode *head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
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
    head = s.rotateRight(head,k);
    s.printLL(head);
    return 0;
}