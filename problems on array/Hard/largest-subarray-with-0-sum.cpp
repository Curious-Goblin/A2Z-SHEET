#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // TLE O(N^2)
    // int maxLen(vector<int> &arr)
    // {
    //     int length = 0, sum = 0, maxLength = 0;
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         length = 0;
    //         sum = 0;
    //         for (int j = i; j < arr.size(); j++)
    //         {
    //             sum += arr[j];
    //             length++;
    //             if (sum == 0)
    //             {
    //                 maxLength = max(length, maxLength);
    //             }
    //         }
    //     }
    //     return maxLength;
    // }

    // OPTIMAL SOLUTION O(N) using a hash map
    int maxLen(vector<int> &arr)
    {
        int sum = 0, maxLength = 0;
        unordered_map<int, int> cumulativeSum;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxLength = i + 1;
            }
            else if (cumulativeSum.find(sum) != cumulativeSum.end())
            {
                maxLength = max(maxLength, i - cumulativeSum[sum]);
            }
            else
            {
                cumulativeSum[sum] = i;
            }
        }
        return maxLength;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    Solution s;
    int result = s.maxLen(arr);
    cout << result;
    return 0;
}