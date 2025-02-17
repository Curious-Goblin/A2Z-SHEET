#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> monotonic;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!monotonic.empty() && nums[monotonic.top()] <= nums[i % n])
            {
                monotonic.pop();
            }
            if (!monotonic.empty())
            {
                result[i % n] = nums[monotonic.top()];
            }
            monotonic.push(i % n);
        }
        return result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution s;
    vector<int> result;
    result = s.nextGreaterElements(nums);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}