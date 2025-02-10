#include "bits/stdc++.h"

using namespace std;

class SortedStack
{
public:
    stack<int> &s;

    SortedStack(stack<int> &input) : s(input) {}

    void sort();
};

void insertSorted(stack<int> &s, int item)
{
    if (s.empty() || s.top() <= item)
    {
        s.push(item);
        return;
    }

    int top = s.top();
    s.pop();
    insertSorted(s, item);
    s.push(top);
}

void SortedStack::sort()
{
    if (s.empty())
    {
        return;
    }

    int top = s.top();
    s.pop();
    sort();
    insertSorted(s, top);
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
    
    stack<int> s;
    
    for (int i = 0; i < n; i++)
    {
        s.push(nums[i]);
    }
    
    SortedStack sortStack(s);
    sortStack.sort();
    
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    
    return 0;
}
