#include "bits/stdc++.h"

using namespace std;

void insertAtBottom(stack<int> &St,int item){
    if(St.empty()){
        St.push(item);
        return;
    }

    int top=St.top();
    St.pop();
    insertAtBottom(St,item);

    St.push(top);
}

void Reverse(std::stack<int> &St)
{
    // std::stack<int> result;
    // while (!St.empty())
    // {
    //     result.push(St.top());
    //     St.pop();
    // }
    // St = result;
    if(St.empty()){
        return;
    }

    int top = St.top();
    St.pop();

    Reverse(St);

    insertAtBottom(St,top);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    stack<int> St;
    for (int i = n-1; i >= 0; i--)
    {
        St.push(nums[i]);
    }
    Reverse(St);
    while(!St.empty()){
        cout<<St.top()<<" ";
        St.pop();
    }
}