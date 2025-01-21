#include "iostream"
#include "vector"
#include "bits/stdc++.h"

using namespace std;

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    int parts = 0, partsum = 0, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        parts = 1, partsum = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (partsum + nums[j] <= mid)
            {
                partsum += nums[j];
            }
            else
            {
                parts++;
                partsum = nums[j];
            }
        }
        if (parts <= k)
        {
            high = mid - 1;
        }
        else if (parts > k)
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = splitArray(nums, k);
    cout << result;
}