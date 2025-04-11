#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> insertionSort(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j > 0 && nums[j - 1] > nums[j])
            {
                swap(nums[j - 1], nums[j]);
                j--;
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
    s.insertionSort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}