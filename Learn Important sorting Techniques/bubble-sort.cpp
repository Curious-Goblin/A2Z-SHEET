#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> bubbleSort(vector<int> &nums)
    {
        int toSwap = nums.size() - 1, maxElementIndex = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 0; j < nums.size() - i - 1; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
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
    s.bubbleSort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}