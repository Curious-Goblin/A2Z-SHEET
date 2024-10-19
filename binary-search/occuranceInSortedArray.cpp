#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    int length = nums.size();
    int first = 0;
    int last = length - 1;
    auto mid = (first + last) / 2;
    vector<int> result = {-1, -1};
    if (length == 0)
    {
        return result;
    }
    if (nums[0] == target)
    {
        result[0] = 0;
        if (nums[length - 1] == target)
        {
            result[1] = length - 1;
            return result;
        }
    }
    if (nums[length - 1] == target)
    {
        result[1] = length - 1;
    }
    // lowerbound
    if (result[0] == -1)
    {
        while (first <= last)
        {
            mid = (first + last) / 2;
            if (nums[mid] == target && nums[mid - 1] != target)
            {
                result[0] = mid;
                break;
            }
            else if (nums[mid] == target)
            {
                last = mid - 1;
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
    }

    // upperbound
    first = 0, last = length - 1;
    if (result[1] == -1)
    {
        while (first <= last)
        {
            mid = (first + last) / 2;
            if (nums[mid] == target && nums[mid + 1] != target)
            {
                result[1] = mid;
                break;
            }
            else if (nums[mid] == target)
            {
                first = mid + 1;
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
    }
    return result;
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
    auto result = searchRange(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}