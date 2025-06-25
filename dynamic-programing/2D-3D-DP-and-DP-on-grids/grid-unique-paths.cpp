#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    const int MOD = 2000000000;
    int memoization(vector<vector<int>>& dp, int row, int column){
        if(row == 0 && column == 0){
            return 1;
        }
        if(row < 0 || column < 0){
            return 0;
        }
        if(dp[row][column] != -1) return dp[row][column];
        int up = memoization(dp, row-1, column);
        int down = memoization(dp, row, column-1);
        return dp[row][column] = (up + down) % MOD;
    }
    int tabulation(vector<vector<int>>& dp, int m, int n){
        int up = 0, down = 0;
        for(int i=0;i<m;i++){
            up = 0, down = 0;
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else{
                    if(i>0) up = dp[i-1][j];
                    if(j>0) down = dp[i][j-1];
                    dp[i][j] = (up + down)% MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
    int spaceOptimized(int m, int n){
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[j] = 1;
                if(i>0) temp[j] += prev[j] % MOD;
                if(j>0) temp[j] += temp[j-1] % MOD;
            }
            prev = temp;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        // return memoization(dp, m-1, n-1);
        // return tabulation(dp, m, n);
        return spaceOptimized(m,n);
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    Solution sol;
    cout<<sol.uniquePaths(m,n);
    return 0;
}