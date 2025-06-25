#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int memoization(vector<int> &nums, vector<int> &dp, int index){
        if(index == 0) return nums[0];
        if(index == 1) return max(nums[0], nums[1]);
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + memoization(nums, dp, index-2);
        int skip = memoization(nums, dp, index-1);
        return dp[index] = max(pick, skip);
    }
    int tabulation(vector<int> &nums){
        int prev = nums[0];
        int prev2 = 0, curr = 0;
        for(int i=1;i<nums.size();i++){
            int pick = nums[i];
            if(i>1) pick += prev2;
            int skip = prev;
            curr = max(pick, skip);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int> &nums){
        // return memoization(nums, dp, nums.size()-1);
        return tabulation(nums);
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
}