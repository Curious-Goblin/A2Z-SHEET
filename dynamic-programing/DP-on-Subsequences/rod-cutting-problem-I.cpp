#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int recursion(vector<int> &price, int length, int index){
        if(index == 0){
            int skip = 0;
            int take = 0;
            if(1 <= length){
                take = price[0] + recursion(price, length - 1, index);
            }
            return max(skip, take);
        }
        int skip = recursion(price, length, index-1);
        int take = 0;
        if(index + 1 <= length){
            take = price[index] + recursion(price, length - index - 1, index);
        }
        return max(skip, take);
    }
    int memoization(vector<int> &price, vector<vector<int>> &dp, int length, int index){
        if(index == 0){
            int skip = 0;
            int take = 0;
            if(1 <= length){
                take = price[0] + memoization(price, dp, length - 1, index);
            }
            return max(skip, take);
        }
        if(dp[index][length]!=0) return dp[index][length];
        int skip = memoization(price, dp, length, index-1);
        int take = 0;
        if(index + 1 <= length){
            take = price[index] + memoization(price, dp, length - index - 1, index);
        }
        return dp[index][length] = max(skip, take);
    }
    int tabulation(vector<int> &price, vector<vector<int>> &dp){
        int length = price.size();
        for(int i=1;i<=length;i++){
            int skip = 0;
            int take = 0;
            if(1<=i){
                take = price[0] + dp[0][i-1];
            }
            dp[0][i] = max(skip,take);
        }
        for(int i=1;i<length;i++){
            for(int j=1;j<=length;j++){
                int skip = dp[i-1][j];
                int take = 0;
                if(i + 1 <= j){
                    take = price[i] + dp[i][j-i-1];
                }
                dp[i][j] = max(skip,take);
            }
        }
        return dp[length-1][length];
    }
    int spaceOptimized(vector<int> &price){
        int length = price.size();
        vector<int> prev(length + 1, 0), curr(length + 1, 0);
        for(int i=1;i<=length;i++){
            int skip = 0;
            int take = 0;
            if(1<=i){
                take = price[0] + prev[i-1];
            }
            prev[i] = max(skip,take);
        }
        for(int i=1;i<length;i++){
            for(int j=1;j<=length;j++){
                int skip = prev[j];
                int take = 0;
                if(i + 1 <= j){
                    take = price[i] + curr[j-i-1];
                }
                curr[j] = max(skip,take);
            }
            prev = curr;
        }
        return prev[length];
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        // return recursion(price, n, n-1);   
        // vector<vector<int>> dp(n, vector<int>(n+1,0));
        // return memoization(price, dp, n, n-1);
        // return tabulation(price, dp);
        return spaceOptimized(price);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    Solution sol;
    cout<<sol.cutRod(price);
    return 0;
}