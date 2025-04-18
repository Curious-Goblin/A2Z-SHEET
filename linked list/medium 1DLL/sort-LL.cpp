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
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head, *fast = head,*prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow ->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = nullptr;
        return slow;
    }
    ListNode *mergeList(ListNode *leftHead, ListNode *rightHead){
        ListNode *head = new ListNode(0);
        ListNode *current = head;

        while(leftHead && rightHead){
            if(leftHead->val < rightHead->val){
                current->next = leftHead;
                leftHead=leftHead->next;
            }
            else{
                current->next = rightHead;
                rightHead=rightHead->next;
            }
            current = current->next;
        }
        while(leftHead){
            current->next = leftHead;
            leftHead=leftHead->next;
            current = current->next;
        }
        while(rightHead){
            current->next = rightHead;
            rightHead=rightHead->next;
            current = current->next;
        }
        return head->next;
    }
    ListNode *sortList(ListNode *head){
        if(!head || !head->next){
            return head;
        }

        ListNode *middle = findMiddle(head);

        ListNode *leftHead = sortList(head);
        ListNode *rightHead = sortList(middle);

        return mergeList(leftHead,rightHead);
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
    head = s.sortList(head);
    s.printLL(head);
    return 0;
}