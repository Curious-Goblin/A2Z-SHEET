#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int memoization(vector<int>& nums, vector<int>& dp, int index) {
        if (index == 0)
            return nums[0];
        if (index == 1)
            return max(nums[0], nums[1]);
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + memoization(nums, dp, index - 2);
        int skip = memoization(nums, dp, index - 1);
        return dp[index] = max(pick, skip);
    }
    int tabulation(vector<int>& nums, int start, int end) {
        int prev = nums[start];
        int prev2 = 0, curr = 0;
        for (int i = start + 1; i <= end; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int skip = prev;
            curr = max(pick, skip);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        // return memoization(nums, dp, nums.size()-1);
        int size = nums.size(), start = 0, end = size - 1, res2 = INT_MIN, res1 = INT_MIN;
        res2 = tabulation(nums, start, end - 1);
        if(size > 1) res1 = tabulation(nums, start + 1, end);
        return max(res2, res1);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.rob(nums);
    return 0;
};