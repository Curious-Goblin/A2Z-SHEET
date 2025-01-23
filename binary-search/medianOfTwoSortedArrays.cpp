#include "bits/stdc++.h"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = 0, m = 0;
    double result=0.00000;
    vector<int> nums3;
    while (n < nums1.size() && m < nums2.size())
    {
        if (nums1[n] <= nums2[m])
        {
            nums3.push_back(nums1[n]);
            n++;
        }
        else if (nums1[n] > nums2[m])
        {
            nums3.push_back(nums2[m]);
            m++;
        }
    }
    if (n < nums1.size())
    {
        for (int i = n; i < nums1.size(); i++)
        {
            nums3.push_back(nums1[i]);
        }
    }
    else if (m < nums2.size())
    {
        for (int i = m; i < nums2.size(); i++)
        {
            nums3.push_back(nums2[i]);
        }
    }
    if (nums3.size() % 2 == 0)
    {
        result += static_cast<double>(nums3[nums3.size() / 2] + nums3[(nums3.size() - 1) / 2]) / 2;
    }
    else
    {
        result += static_cast<double>(nums3[nums3.size() / 2]);
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    double result = findMedianSortedArrays(nums1, nums2);
    cout<<result;
    return 0;
}