#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    // TLE O(n*2)
    // int countSubarrays(vector<int> &arr, int k)
    // {
    //     int count = 0, sum = 0;
    //     for (int i = 0; i < arr.size(); i++)
    //     {
    //         sum = arr[i];
    //         if (sum == k)
    //         {
    //             count++;
    //         }
    //         for (int j = i + 1; j < arr.size(); j++)
    //         {
    //             sum += arr[j];
    //             if (sum == k)
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }

    // optimal solution using the concept of prefix sum
    int countSubarrays(vector<int> &arr, int k)
    {
        map<int, int> prefixSumFreq;
        int currSum = 0, count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            currSum += arr[i];
            auto it = prefixSumFreq.find(currSum - k);
            if (it != prefixSumFreq.end())
            {
                count += it->second;
            }
            if (currSum == k)
            {
                count++;
            }
            auto it1 = prefixSumFreq.find(currSum);
            if (it1 != prefixSumFreq.end())
            {
                it1->second += 1;
            }
            else
            {
                prefixSumFreq[currSum] = 1;
            }
        }
        return count;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Solution s;
    int count = s.countSubarrays(arr, k);
    cout << count;
    return 0;
}