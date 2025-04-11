#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> selectionSort(vector<int> &nums)
    {
        int toSwap = 0, minElementIndex = 0;
        for (int i = toSwap; i < nums.size(); i++)
        {
            minElementIndex = toSwap;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[minElementIndex])
                {
                    minElementIndex = j;
                }
            }
            swap(nums[toSwap],nums[minElementIndex]);
            toSwap++;
        }
        return nums;
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
    vector<int> sortedNums = s.selectionSort(nums);
    for (int i = 0; i < sortedNums.size(); i++)
    {
        cout << sortedNums[i] << " ";
    }
    return 0;
}