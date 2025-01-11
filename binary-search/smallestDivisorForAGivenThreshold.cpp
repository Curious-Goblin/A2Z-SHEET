#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"

using namespace std;

int smallestDivisor(vector<int> &nums, int threshold)
{
    int low = 1, high = *max_element(nums.begin(), nums.end()), mid, sum = 0;
    while (low <= high)
    {
        mid = (low + high) / 2,sum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            double result = static_cast<double>(nums[i]) / mid;
            sum = sum + static_cast<int>(ceil(result));
        }
        if (sum > threshold)
        {
            low = mid + 1;
        }
        else if (sum <= threshold)
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int n, threshold;
    cin >> n >> threshold;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int result = smallestDivisor(nums, threshold);
    cout << result;
    return 0;
}