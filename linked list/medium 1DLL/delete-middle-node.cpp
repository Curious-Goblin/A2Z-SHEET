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
    // O(N) constant space complexity
    ListNode* deleteMiddle(ListNode *head){
        if(!head || !head->next){
            return nullptr;
        }
        ListNode *slow=head,*fast=head,*prev=head;
        while(fast && fast->next){
            prev=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = prev->next->next;
        return head;
    }

    ListNode *constructLL(vector<int> &nums){
        ListNode *head = new ListNode(nums[0]);
        ListNode *current = head;
        for(int i=1;i<nums.size();i++){
            current->next = new ListNode(nums[i]);
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
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    ListNode *head = s.constructLL(nums);
    head = s.deleteMiddle(head);
    s.printLL(head);
    return 0;
}