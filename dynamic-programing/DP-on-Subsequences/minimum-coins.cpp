#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recusion(vector<int>& coins, int index, int amount){
        if(amount == 0) return 0;
        if(index == 0){
            if(amount%coins[index] == 0) return amount/coins[index];
            else{
                return INT_MAX;
            }
        }
        int skip = 0+recusion(coins, index-1, amount);
        int take = INT_MAX;
        if(coins[index] <= amount){
            int res = recusion(coins, index, amount-coins[index]);
            if(res!=INT_MAX){
                take = 1 + res;
            }
        }
        return min(skip,take);
    }
    int memoization(vector<int> &coins, vector<vector<int>>& dp, int index, int amount){
        if(amount == 0) return 0;
        if(index == 0){
            if(amount%coins[index] == 0) return amount/coins[index];
            else{
                return INT_MAX;
            }
        }
        if(dp[index][amount] != -1) return dp[index][amount];
        int skip = 0+memoization(coins, dp, index-1, amount);
        int take = INT_MAX;
        if(coins[index] <= amount){
            int res = memoization(coins, dp, index, amount-coins[index]);
            if(res!=INT_MAX){
                take = 1 + res;
            }
        }
        return dp[index][amount] = min(skip,take);
    }
    int tabulation(vector<int>& coins, vector<vector<int>>& dp, int amount){
        int n = coins.size();
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=amount;i++){
            if(i%coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = INT_MAX;
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=amount;target++){
                int skip = dp[i-1][target];
                int take = INT_MAX;
                if(coins[i]<=target){
                    int res = dp[i][target - coins[i]];
                    if(res != INT_MAX){
                        take = 1 + res;
                    }
                }
                dp[i][target] = min(skip, take);
            }
        }
        return dp[n-1][amount];
    }
    int spaceOptimized(vector<int> &coins, int amount){
        int n = coins.size();
        vector<int> prev(amount + 1,0);
        prev[0] = 0;
        for(int i=1;i<=amount;i++){
            if(i%coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = INT_MAX;
        }
        for(int i=1;i<n;i++){
            vector<int> curr(amount + 1,0);
            for(int target=1;target<=amount;target++){
                int skip = prev[target];
                int take = INT_MAX;
                if(coins[i]<=target){
                    int res = curr[target - coins[i]];
                    if(res != INT_MAX){
                        take = 1 + res;
                    }
                }
                curr[target] = min(skip, take);
            }
            prev = curr;
        }
        return prev[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        // return recusion(coins, n-1, amount);
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        // int ans = memoization(coins, dp, n-1, amount);
        // int ans = tabulation(coins, dp, amount);
        // return (ans == INT_MAX) ? -1 : ans;
        int ans = spaceOptimized(coins, amount);
        return (ans == INT_MAX) ? -1 : ans;
    }
};

int main(){
    int n, amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    Solution sol;
    cout<<sol.coinChange(coins, amount);
    return 0;
}