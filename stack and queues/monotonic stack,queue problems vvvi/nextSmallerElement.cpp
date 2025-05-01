#include "bits/stdc++.h"

using namespace std;

// O(n)
vector<int> nextSmallerElement(vector<int> &nums)
{
    vector<int> result;
    stack<int> monotonic;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!monotonic.empty() && monotonic.top() >= nums[i])
        {
            monotonic.pop();
        }
        result.push_back(monotonic.empty() ? -1 : monotonic.top());
        monotonic.push(nums[i]);
    }
    return result;
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
    vector<int> result = nextSmallerElement(nums);
    for (int i = result.size()-1; i >= 0; i--)
    {
        cout << result[i] << " ";
    }
    return 0;
}