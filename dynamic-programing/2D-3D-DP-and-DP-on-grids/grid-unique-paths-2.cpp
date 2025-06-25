#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    const int MOD = 2000000000;
    int memoization(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int &row, int &column, int m, int n){
        if(m==0 && n==0){
            if(obstacleGrid[m][n]) return 0;
            return 1;
        }
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return dp[m][n] = 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up = 0, left = 0;
        if(m > 0 && obstacleGrid[m-1][n] != 1) up = memoization(obstacleGrid, dp, row, column, m-1, n);
        if(n > 0 && obstacleGrid[m][n-1] != 1) left = memoization(obstacleGrid, dp, row, column, m, n-1);
        return dp[m][n] = (up + left) % MOD;
    }
    int tabulation(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        int row = obstacleGrid.size(), column = obstacleGrid[0].size(), up = 0, left = 0;
        if(obstacleGrid[0][0]) return 0;
        dp[0][0] = 1; 
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(i==0 && j==0) continue;
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                else{
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up + left) % MOD;
                    up = 0, left = 0;
                }
            }
        }
        return dp[row-1][column-1];
    }
    int spaceOptimized(vector<vector<int>> &obstacleGrid){
        int row = obstacleGrid.size(), column = obstacleGrid[0].size(), up = 0, left = 0;
        if(obstacleGrid[0][0]) return 0;
        vector<int> prev(column, 0);
        for(int i=0;i<row;i++){
            vector<int> curr(column, 0);
            for(int j=0;j<column;j++){
                if(i==0 && j==0){
                    curr[j] = 1;
                    continue;
                }
                if(obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                    continue;
                }
                else{
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up + left) % MOD;
                    up = 0, left = 0;
                }
            }
            prev = curr;
        }
        return prev[column-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), column = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(column,-1));
        // return memoization(obstacleGrid,  dp, row, column, row-1, column-1);
        // return tabulation(obstacleGrid, dp);
        return spaceOptimized(obstacleGrid);
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> obstacleGrid(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>obstacleGrid[i][j];
        }
    }
    Solution sol;
    cout<<sol.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}