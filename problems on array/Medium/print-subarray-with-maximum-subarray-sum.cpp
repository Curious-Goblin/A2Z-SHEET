#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSubArray(vector<int> &nums)
    {
        int maxSum = INT64_MIN;
        int currentSum = 0;
        int startingIndex = 0, lastIndex = 0, tempStart = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currentSum += nums[i];
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                startingIndex = tempStart;
                lastIndex = i;
            }
            if (currentSum < 0)
            {
                currentSum = 0;
                tempStart = i + 1;
            }
        }
        return vector<int>(nums.begin() + startingIndex, nums.begin() + lastIndex + 1);
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
    vector<int> result = s.maxSubArray(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}