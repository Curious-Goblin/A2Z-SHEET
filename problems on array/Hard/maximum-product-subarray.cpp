#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxSoFar = nums[0], currMax = nums[0], currMin = nums[0], temp = 0;
        for (unsigned int i = 1; i < nums.size(); i++)
        {
            temp = currMax;
            currMax = max(nums[i], max(currMax * nums[i], currMin * nums[i]));
            currMin = min(nums[i], min(temp * nums[i], currMin * nums[i]));
            maxSoFar = max(maxSoFar, currMax);
        }
        return maxSoFar;
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
    int result = s.maxProduct(nums);
    cout << result;
    return 0;
}