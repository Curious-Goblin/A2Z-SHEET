#include <bits/stdc++.h>
using namespace std;

int findTargetOrInsertPosition(vector<int> &nums, int target)
{
    int length = nums.size();
    int first = 0;
    int last = length - 1;
    auto mid = (first + last) / 2;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    if (nums[mid] < target)
    {
        return mid + 1;
    }
    else if (nums[mid] > target)
    {
        return mid;
    }
    return 0;
}

int main()
{
    int n, target, sample;
    cin >> n;
    cin >> target;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> sample;
        nums.push_back(sample);
    }
    cout << findTargetOrInsertPosition(nums, target);
    return 0;
}