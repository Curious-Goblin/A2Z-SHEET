#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(int index, vector<int>& coins, int target){
        if(index == 0){
            if(target%coins[index] == 0) return 1;
            else if(target == 0) return 1;
            else return 0;
        }
        int skip = recursion(index-1, coins, target);
        int take = 0;
        if(coins[index] <= target){
            take = recursion(index, coins, target - coins[index]);
        }
        return skip + take;
    }
    int memoization(vector<vector<int>>& dp, vector<int>& coins, int target, int index){
        if(index == 0){
            if(target % coins[index] == 0) return 1;
            else if(target == 0) return 1;
            else return 0;
        }
        if(dp[index][target] != 0) return dp[index][target];
        int skip = memoization(dp, coins, target, index-1);
        int take = 0;
        if(coins[index] <= target){
            take = memoization(dp, coins, target - coins[index], index);
        }
        return dp[index][target] = skip + take;
    }
    int tabulation(vector<vector<int>>& dp, vector<int>& coins, int target){
        int n = coins.size();
        for(int i=1;i<=target;i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
        }
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int amount=1;amount<=target;amount++){
                int skip = dp[i-1][amount];
                int take = 0;
                if(coins[i] <= amount){
                    take = dp[i][amount-coins[i]];
                }
                dp[i][amount] = skip + take;
            }
        }
        return dp[n-1][target];
    }
    int spaceOptimized(vector<int>& coins, int target){
        int n = coins.size();
        using ULL = unsigned long long;
        vector<ULL> prev(target + 1,0), curr(target + 1, 0);
        prev[0] = curr[0] = 1;
        for(int i=1;i<=target;i++){
            if(i % coins[0] == 0) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int amount=1;amount<=target;amount++){
                ULL skip = prev[amount];
                ULL take = 0;
                if(coins[i] <= amount){
                    take = curr[amount - coins[i]];
                }
                curr[amount] = skip + take;
            }
            prev = curr;
        }
        return (prev[target] > INT_MAX) ? -1 : static_cast<int>(prev[target]);
    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        int n = coins.size();
        // return recursion(n-1, coins, amount);
        // vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        // return memoization(dp, coins, amount, n-1);
        // return tabulation(dp, coins, amount);
        return spaceOptimized(coins, amount);
    }
};

int main(){
    int n, amount;
    cin>>n>>amount;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.change(amount, nums);
    return 0;
}