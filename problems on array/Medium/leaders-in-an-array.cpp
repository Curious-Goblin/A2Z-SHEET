#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> leaders(vector<int> &nums)
    {
        vector<int> leaders;
        leaders.push_back(nums[nums.size() - 1]);
        if (nums.size() == 1)
        {
            return leaders;
        }
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] >= leaders[leaders.size() - 1])
            {
                leaders.push_back(nums[i]);
            }
        }
        vector<int> result;
        for (int i = leaders.size() - 1; i >= 0; i--)
        {
            result.push_back(leaders[i]);
        }
        return result;
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
    vector<int> leaders = s.leaders(nums);
    for (int i = 0; i < leaders.size(); i++)
    {
        cout << leaders[i] << " ";
    }
    return 0;
}