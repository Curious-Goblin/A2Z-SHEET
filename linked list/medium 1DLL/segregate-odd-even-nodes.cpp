#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    
    ListNode(int value){
     val = value;
        next = nullptr;
    }
};

class Solution{
    public:
    // ListNode *oddEvenList(ListNode *head){
    //     vector<int> nums,odd,even;
    //     ListNode *current = head;
    //     while(current){
    //         nums.push_back(current-> val);
    //         current = current->next;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         if(i%2==0){
    //             odd.push_back(nums[i]);
    //         }
    //         else{
    //             even.push_back(nums[i]);
    //         }
    //     }
    //     current = head;
    //     for(int i=0;i<odd.size();i++){
    //         current-> val = odd[i];
    //         current = current->next;
    //     }
    //     for(int i=0;i<even.size();i++){
    //         current-> val = even[i];
    //         current = current->next;
    //     }
    //     return head;
    // }

    ListNode *oddEvenList(ListNode *head){
        if(!head || !head->next){
            return head;
        }

        ListNode *current = head;
        ListNode *current_odd_node = head;
        ListNode *current_even_node = head->next;
        ListNode *even_head = current_even_node;

        int count = 2;
        current = current->next->next;
        while(current){
            count++;
            if(count%2!=0){
                current_odd_node->next = current;
                current_odd_node = current_odd_node->next;
            }
            else{
                current_even_node->next = current;
                current_even_node= current_even_node->next;
            }
            current = current->next;
        }
        current_odd_node->next = even_head;
        current_even_node->next = nullptr;
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
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i =0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    ListNode *head = s.constructLL(nums);
    ListNode *newHead = s.oddEvenList(head);
    s.printLL(newHead);
    return 0;
}