#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int>& nums, int start, int end){
        if(start > end) return 0;
        int coins = 0, finally = 0;
        for(int i=start;i<=end;i++){
            coins = nums[start-1] * nums[i] * nums[end+1] + recursion(nums, start, i-1) + recursion(nums, i+1, end);
            finally = max(finally, coins);
        }
        return finally;
    }
    int memoization(vector<int>& nums, int start, int end, vector<vector<int>> &dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int coins = 0, finally = 0;
        for(int i = start; i <= end; i++){
            coins = nums[start-1] * nums[i] * nums[end + 1] + memoization(nums, start, i-1, dp) + memoization(nums, i+1, end, dp);
            finally = max(finally, coins);
        }
        return finally;
    }
    int tabulation(vector<int> &nums, vector<vector<int>> &dp){
        int len = nums.size();
        len -= 2;
        for(int i=len;i>=1;i--){
            for(int j=i;j<=len;j++){
                int coins = 0, finally = 0;
                for(int k = i; k <= j; k++){
                    coins = nums[i-1] * nums[k] * nums[j + 1] + dp[i][k-1] + dp[k+1][j];
                    finally = max(finally, coins);
                }
                dp[i][j] = finally;
            }
        }
        return dp[1][len];
    }
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        // vector<vector<int>> dp(len+1, vector<int>(len+1,-1));
        // return recursion(nums, 1, len);
        // return memoization(nums, 1, len, dp);
        vector<vector<int>> dp(len+2, vector<int>(len+2,0));
        return tabulation(nums, dp);
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
    cout<<sol.maxCoins(nums);
    return 0;
}