#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(int id, int buy, int cooldown, vector<int>& prices){
        if(id == prices.size()) return 0;
        if(buy){
            if(!cooldown){
                return max(-prices[id] + recursion(id+1, 0, 0, prices), recursion(id+1, 1, 0, prices));
            }
            else{
                return recursion(id+1, 1, 0, prices);
            }
        }
        else return max(prices[id] + recursion(id+1, 1, 1, prices), recursion(id+1, 0, 0, prices));
    }
    int memoization(int id, int buy, int cooldown, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(id == prices.size()) return 0;
        if(dp[id][buy][cooldown] != -1) return dp[id][buy][cooldown];
        if(buy){
            if(!cooldown){
                return dp[id][buy][cooldown] = max(-prices[id] + memoization(id+1, 0, 0, prices, dp), memoization(id+1, 1, 0, prices, dp));
            }
            else{
                return dp[id][buy][cooldown] = memoization(id+1, 1, 0, prices, dp);
            } 
        }
        else return dp[id][buy][cooldown] = max(prices[id] + memoization(id+1, 1, 1, prices, dp), memoization(id+1, 0, 0, prices, dp));
    }
    int tabulation(vector<int>& prices, vector<vector<vector<int>>> &dp){
        int n = prices.size();
        for(int i = n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cooldown=0;cooldown<=1;cooldown++){
                    if(buy) {
                        if(!cooldown){
                            dp[i][buy][cooldown] = max(dp[i+1][1][cooldown], -prices[i] + dp[i+1][0][cooldown]);
                        }
                        else {
                            dp[i][buy][cooldown] = dp[i+1][1][0];
                        }
                    }
                    else dp[i][buy][cooldown] = max(dp[i+1][0][0], prices[i] + dp[i+1][1][1]);
                }
            }
        }
        return dp[0][1][0];
    }
    int spaceOptimized(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(2, 0)), next(2,vector<int>(2,0));
        for(int i = n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cooldown=0;cooldown<=1;cooldown++){
                    if(buy) {
                        if(!cooldown){
                            curr[buy][cooldown] = max(next[1][cooldown], -prices[i] + next[0][cooldown]);
                        }
                        else {
                            curr[buy][cooldown] = next[1][0];
                        }
                    }
                    else curr[buy][cooldown] = max(next[0][0], prices[i] + next[1][1]);
                }
            }
            next = curr;
        }
        return next[1][0];
    }

    int maxProfit(vector<int>& prices) {
        // return recursion(0, 1, 0, prices);
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        // return memoization(0, 1, 0, prices, dp);
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(2, 0)));
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