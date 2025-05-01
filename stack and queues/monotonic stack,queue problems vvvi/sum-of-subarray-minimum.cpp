#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    vector<int> nextSmallerElementLeft(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!monotonic.empty() && nums[monotonic.top()] > nums[i])
            {
                monotonic.pop();
            }
            result.push_back(monotonic.empty() ? -1 : monotonic.top());
            monotonic.push(i);
        }
        return result;
    }
    vector<int> nextSmallerElementRight(vector<int> &nums)
    {
        vector<int> result;
        stack<int> monotonic;
        for (int i = nums.size()-1; i >= 0; i--)
        {
            while (!monotonic.empty() && nums[monotonic.top()] >= nums[i])
            {
                monotonic.pop();
            }
            result.push_back(monotonic.empty() ? -1 : monotonic.top());
            monotonic.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
    // O(3n)
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left = nextSmallerElementLeft(arr);
        vector<int> right = nextSmallerElementRight(arr);
        long long int minimum = 0;
        int leftCount = 0, rightCount = 0;
        const int MOD = 1e9 + 7;
        for(int i=0;i<arr.size();i++){
            leftCount = (left[i] == -1) ? i + 1 : i-left[i];
            rightCount = (right[i] == -1) ? arr.size()-i : right[i] - i; 
            minimum  = (minimum + (1LL * arr[i] * leftCount * rightCount) % MOD) % MOD;
            leftCount = 0, rightCount = 0;
        }
        return minimum;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    int result = s.sumSubarrayMins(nums);
    cout<<result;
    return 0;
}