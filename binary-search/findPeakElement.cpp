#include "iostream"
#include "vector"

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int peakElement = -1;
    int low = 0, high = nums.size() - 1;
    if (low == high)
    {
        peakElement = 0;
        return peakElement;
    }
    if (nums[low] > nums[low + 1])
    {
        peakElement = low;
        return peakElement;
    }
    if (nums[high] > nums[high - 1])
    {
        peakElement = high;
        return peakElement;
    }
    low++, high--;
    while (low <= high)
    {
        if (nums[low - 1] < nums[low] && nums[low] > nums[low + 1])
        {
            peakElement = low;
            break;
        }
        if (nums[high - 1] < nums[high] && nums[high] > nums[high + 1])
        {
            peakElement = high;
            break;
        }
        low++;
        high--;
    }
    return peakElement;
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
    int result = findPeakElement(nums);
    cout << result;
    return 0;
}