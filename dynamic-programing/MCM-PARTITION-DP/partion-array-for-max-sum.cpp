#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int> &nums, int k, int start){
        if(start == nums.size()) return 0;
        int n = nums.size();
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        int len = 0;
        for(int j = start; j < min(start + k, n); j++){
            len = j - start + 1;
            maxi = max(maxi, nums[j]);
            int sum = (len * maxi) + recursion(nums, k, j + 1);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }
    int memoization(vector<int> &nums, int k, int start, vector<int> &dp){
        if(start == nums.size()) return 0;
        if(dp[start] != -1) return dp[start];
        int n = nums.size();
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        int len = 0;
        for(int j = start; j < min(start + k, n); j++){
            len = j - start + 1;
            maxi = max(maxi, nums[j]);
            int sum = (len * maxi) + memoization(nums, k, j + 1, dp);
            maxAns = max(maxAns, sum);
        }
        return dp[start] = maxAns;
    }
    int tabulation(vector<int> &nums, int k, vector<int> &dp){
        int n = nums.size();
        for(int start = n-1; start >= 0; start--){
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            int len = 0;
            for(int j = start; j < min(start + k, n); j++){
                len++;
                maxi = max(maxi, nums[j]);
                int sum = (len * maxi) + dp[j+1];
                maxAns = max(maxAns, sum);
            }
            dp[start] = maxAns;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();
        // return recursion(nums, k, 0);
        // vector<int> dp(n, -1);
        // return memoization(nums, k, 0, dp);
        vector<int> dp(n + 1, 0);
        return tabulation(nums, k, dp);
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.maxSumAfterPartitioning(nums, k);
    return 0;
}