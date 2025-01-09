#include "bits/stdc++.h"
#include "vector"
using namespace std;

int findMinimum(vector<int> &nums, int rotation)
{
    int low = 0;
    int high = nums.size() - 1;
    int minimum = 5000;
    while (low <= high)
    {
        if (nums.size() == 1)
        {
            minimum = nums[0];
            break;
        }
        int mid = (low + high) / 2;
        if (nums[low] <= nums[mid])
        {
            if (nums[low] < minimum)
            {
                minimum = nums[low];
            }
            low = mid + 1;
        }
        else
        {
            if (nums[mid] < minimum)
            {
                minimum = nums[mid];
                high = mid - 1;
            }
        }
    }
    return minimum;
}

int main()
{
    int n, a = 0, rotation;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    cin >> rotation;
    int result = findMinimum(nums, rotation);
    cout << result << endl;
    return 0;
}