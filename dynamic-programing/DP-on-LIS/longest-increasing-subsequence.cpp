#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int>& nums, int id, int prev){
        if(id == nums.size()){
            return 0;
        }
        int skip = recursion(nums, id+1, prev), pick = INT_MIN;
        if(prev == -1 || nums[id] > nums[prev]){
            pick = 1 + recursion(nums, id+1, id);
        }
        return max(skip, pick);
    }
    int memoization(vector<int>& nums, vector<vector<int>>& dp, int id, int prev){
        if(id == nums.size()){
            return 0;
        }
        if(dp[id][prev+1] != -1) return dp[id][prev+1];
        int skip = recursion(nums, id+1, prev), pick = INT_MIN;
        if(prev == -1 || nums[id] > nums[prev]){
            pick = 1 + recursion(nums, id+1, id);
        }
        return dp[id][prev+1] = max(skip, pick);
    }
    int tabulation(vector<int>& nums, vector<vector<int>>& dp){
        int n = nums.size();
        for(int i=n-1; i >= 0; i--){
            for(int prev=-1; prev <= n-1; prev++){
                int skip = dp[i+1][prev+1], pick = INT_MIN;
                if(prev == -1 || nums[i] > nums[prev]){
                    pick = 1 + dp[i+1][i+1];
                }
                dp[i][prev+1] = max(skip, pick);
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<int>& nums){
        int n = nums.size();
        vector<int> curr(n+1, 0), next(n+1, 0);
        for(int i=n-1; i >= 0; i--){
            for(int prev=-1; prev <= n-1; prev++){
                int skip = next[prev+1], pick = INT_MIN;
                if(prev == -1 || nums[i] > nums[prev]){
                    pick = 1 + next[i+1];
                }
                curr[prev+1] = max(skip, pick);
            }
            next = curr;
        }
        return next[0];
    }
    int tabulation2(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
    int binarySearchSolution(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            } else {
                int id = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[id] = nums[i];
            }
        }
        return temp.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // return recursion(nums, 0, -1);
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n+1,-1));
        // return memoization(nums, dp, 0, -1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return tabulation(nums, dp);
        // return spaceOptimized(nums);
        // return tabulation2(nums);
        // return binarySearchSolution(nums);
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
    cout<<sol.lengthOfLIS(nums);
    return 0;
}