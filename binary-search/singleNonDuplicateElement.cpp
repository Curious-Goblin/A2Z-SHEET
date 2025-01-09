#include "iostream"
#include "vector"

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1, mid = 0;
    int result = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (low == high)
        {
            result = nums[mid];
            break;
        }
        if (nums[low] == nums[low + 1] && nums[high] == nums[high - 1])
        {
            low = low + 2;
            high = high - 2;
        }
        if (nums[low] != nums[low + 1])
        {
            result = nums[low];
            break;
        }
        if (nums[high] != nums[high - 1])
        {
            result = nums[high];
            break;
        }
    }
    return result;
}

// lower complexity solution

int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
            left = mid + 1;
        else
            right = mid;
    }

    return nums[left];
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
    int result = singleNonDuplicate(nums);
    cout << result;
    return 0;
}