#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(int id, int buy, int count, vector<int>& prices){
        if(id == prices.size() || count == 0) return 0;
        if(buy){
            return max(-prices[id] + recursion(id+1, 0, count, prices), recursion(id+1, 1, count, prices));
        }
        else return max(prices[id] + recursion(id+1, 1, count-1, prices), recursion(id+1, 0, count , prices));
    }
    int memoization(int id, int buy, int count, vector<int>&prices, vector<vector<vector<int>>>& dp){
        if(id == prices.size() || count == 0) return 0;
        if(dp[id][buy][count] != -1) return dp[id][buy][count];
        if(buy){
            return dp[id][buy][count] = max(-prices[id] + memoization(id+1, 0, count, prices, dp), memoization(id+1, 1, count, prices, dp));
        }
        else return dp[id][buy][count] = max(prices[id] + memoization(id+1, 1, count - 1, prices, dp), memoization(id+1, 0, count , prices, dp));
    }
    int tabulation(vector<int>& prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    if(buy){
                        dp[i][buy][count] = max(-prices[i] + dp[i+1][0][count], dp[i+1][1][count]);
                    }
                    else {
                        if(count > 0){
                            dp[i][buy][count] = max(prices[i] + dp[i+1][1][count-1], dp[i+1][0][count]);
                        }
                        else{
                            dp[i][buy][count] = dp[i+1][0][count];
                        }
                    }
                }
            }
        }
        return dp[0][1][2];
    }
    int spaceOptimized(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3,0)), next(2, vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    if(buy){
                        curr[buy][count] = max(-prices[i] + next[0][count], next[1][count]);
                    }
                    else {
                        if(count > 0){
                            curr[buy][count] = max(prices[i] + next[1][count-1], next[0][count]);
                        }
                        else{
                            curr[buy][count] = next[0][count];
                        }
                    }
                }
            }
            next = curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        // return recursion(0, 1, 2, prices);
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        // return memoization(0, 1, 2, prices, dp);
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