#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node *random;

    Node(int data){
        val = data;
        next = nullptr;
        random = nullptr;
    }
};

class Solution{
    public:
    Node *copyRandomList(Node *head){
        Node *current = head;
        while(current){
            Node *cloned = new Node(current->val);
            cloned->next=current->next;
            current->next = cloned;
            current = cloned->next;
        }
        current = head;
        while(current){
            if(current->random){
                current->next->random = current->random->next;
            }
            else{
                current->next->random = nullptr;
            }
            current = current->next->next;
        }
        current = head;
        Node *clonedHead = head->next;
        Node *clonedCurrent = clonedHead;
        while(current){
            current->next = current->next->next;
            if(clonedCurrent->next)
            {
                clonedCurrent->next = clonedCurrent->next->next;
            }
            else{
                clonedCurrent->next = nullptr;
            }
            clonedCurrent = clonedCurrent->next;
            current = current->next;
        }
        return clonedHead;
    }
    Node *constructLL(vector<pair<int,int>> &nums){
        if(nums.empty()){
            return nullptr;
        }
        Node *head = new Node(nums[0].first);
        Node *current = head;
        vector<Node *> nodeRef;
        nodeRef.push_back(head);
        // int count = 0;
        for(int i=1;i<nums.size();i++){
            current->next = new Node(nums[i].first);
            current = current->next;
            nodeRef.push_back(current);
        }

        current = head;
        for(int i=0;i<nums.size();i++){
            if(nums[i].second != INT32_MIN){
                current->random = nodeRef[nums[i].second];
            }
            else{
                current->random = nullptr;
            }
            current = current->next;
        }

        // Node *currentNode = head;
        // for(int i=0;i<nums.size();i++){
        //     current = head;
        //     count=0;
        //     if(nums[i].second != INT32_MIN){
        //         while(count != nums[i].second){
        //             count++;
        //             current = current->next;
        //         }
        //         currentNode->random = current;
        //     }
        //     else{
        //         currentNode->random = nullptr;
        //     }
        //     currentNode = currentNode->next;

        // }
        return head;
    }
    void printLL(Node *head){
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
    }
};

int main(){
    int n,a,b;
    string s;
    cin>>n;
    vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>s;
        b = (s != "null") ? stoi(s) : INT32_MIN;
        nums.push_back({a,b});
    }
    Solution solve;
    Node *head = solve.constructLL(nums);
    head = solve.copyRandomList(head);
    solve.printLL(head);
}