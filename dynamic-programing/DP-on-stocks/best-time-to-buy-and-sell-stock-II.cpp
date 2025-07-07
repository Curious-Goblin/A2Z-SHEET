#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(int id, int buy, vector<int>& prices){
        if(id == prices.size()) return 0;
        if(buy){
            return max(-prices[id] + recursion(id+1, 0, prices), recursion(id+1, 1, prices));
        }
        else return max(prices[id] + recursion(id+1, 1, prices), recursion(id+1, 0, prices));
    }
    int memoization(int id, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(id == prices.size()) return 0;
        if(dp[id][buy] != -1) return dp[id][buy];
        if(buy){
            return dp[id][buy] = max(-prices[id] + recursion(id+1, 0, prices), recursion(id+1, 1, prices));
        }
        else return dp[id][buy] = max(prices[id] + recursion(id+1, 1, prices), recursion(id+1, 0, prices));
    }
    int tabulation(vector<int>& prices, vector<vector<int>> &dp){
        int n = prices.size();
        for(int i = n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy) dp[i][buy] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
                else dp[i][buy] = max(dp[i+1][0], prices[i] + dp[i+1][1]);
            }
        }
        return dp[0][1];
    }
    int spaceOptimized(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0), next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy) curr[buy] = max(next[1], -prices[i]+next[0]);
                else curr[buy] = max(next[0], prices[i] + next[1]);
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        // return recursion(0, 1, prices);
        int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return memoization(0, 1, prices, dp);
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // return tabulation(prices, dp);
        return spaceOptimized(prices);
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
    cout<<sol.maxProfit(nums);
    return 0;
}