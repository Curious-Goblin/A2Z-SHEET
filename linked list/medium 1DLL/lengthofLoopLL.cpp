#include "bits/stdc++.h"

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// int countNodesinLoop(Node *head)
// {
//   unordered_map<Node *,int> map;
//     Node *current = head;
//     int start=0;
//     int count =0;
//     while(current){
//         count++;
//         map.insert({current,count});
//         auto it = map.find(current->next);
//         if(it!=map.end()){
//             return count - it->second + 1;
//         }
//         current=current->next;
//     }
//     return 0;
// }

// optimal approach

int countNodesinLoop(Node *head)
{
    Node *slow = head,*fast = head;
    while(fast && fast->next){
        slow = slow ->next;
        fast = fast->next->next;
        if(slow==fast){
            int count =1;
            Node *temp =slow;
            while(temp->next != slow){
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}

int main()
{
    return 0;
}