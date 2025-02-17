#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    // vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    // {
    //     vector<int> result;
    //     for (int i = 0; i < nums1.size(); i++)
    //     {
    //         for (int j = 0; j < nums2.size(); j++)
    //         {
    //             if (nums2[j] == nums1[i])
    //             {
    //                 for (int k = j + 1; k < nums2.size(); k++)
    //                 {
    //                     if (nums2[k] > nums2[j])
    //                     {
    //                         result.push_back(nums2[k]);
    //                     }
    //                     else if (k == nums2.size() - 1)
    //                     {
    //                         result.push_back(-1);
    //                     }
    //                     break;
    //                 }
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }

    // vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    // {
    //     vector<int> result;
    //     unordered_map<int, int> hash;
    //     for (int i = 0; i < nums2.size(); i++)
    //     {
    //         for (int j = i + 1; j < nums2.size(); j++)
    //         {
    //             if (nums2[j] > nums2[i])
    //             {
    //                 hash[nums2[i]] = nums2[j];
    //                 break;
    //             }
    //             else if (j == nums2.size() - 1)
    //             {
    //                 hash[nums2[i]] = -1;
    //                 break;
    //             }
    //         }
    //     }
    //     hash.insert({nums2[nums2.size() - 1], -1});
    //     for (int i = 0; i < nums1.size(); i++)
    //     {
    //         auto it = hash.find(nums1[i]);
    //         result.push_back(it->second);
    //     }
    //     return result;
    // }

    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        stack<int> monotonic;
        unordered_map<int, int> hash;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!monotonic.empty() && monotonic.top() <= nums2[i])
            {
                monotonic.pop();
            }
            if (monotonic.empty())
            {
                hash[nums2[i]] = -1;
            }
            else
            {
                hash[nums2[i]] = monotonic.top();
            }
            monotonic.push(nums2[i]);
        }
        for(int num:nums1){
            result.push_back(hash[num]);
        }
        return result;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(m), nums2(n), result;
    for (int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    Solution s;
    result = s.nextGreaterElement(nums1, nums2);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}