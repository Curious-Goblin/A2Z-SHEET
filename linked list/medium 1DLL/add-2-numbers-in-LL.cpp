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
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
        ListNode *head1=l1,*head2=l2;
        ListNode *sum = new ListNode(0);
        ListNode *head3 = sum;
        int carry=0;
        while(head1 || head2 || carry){
            int val1 = (head1)?head1->val:0;
            int val2 = (head2)?head2->val:0;
            int total = val1 + val2 + carry;
            // whenever a number is a two digit then the right digit goes into the list and 
            // the left digit goes into the carry.
            carry = total/10;
            sum->next = new ListNode (total%10);
            sum = sum->next;
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        return (head3->next);
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
    int n,m;
    cin>>n>>m;
    vector<int> nums1(n),nums2(m);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    Solution s;
    ListNode *head1 = s.constructLL(nums1);
    ListNode *head2 = s.constructLL(nums2);
    ListNode *head3 = s.addTwoNumbers(head1,head2);
    s.printLL(head3);
}