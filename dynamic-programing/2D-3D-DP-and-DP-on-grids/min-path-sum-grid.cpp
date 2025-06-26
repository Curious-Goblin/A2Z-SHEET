#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int memoization(vector<vector<int>>& grid, vector<vector<int>>& dp,
                    int& row, int& column, int m, int n) {
        if (m == 0 && n == 0)
            return grid[m][n];
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != INT_MAX)
            return dp[m][n];
        int up = INT_MAX, left = INT_MAX;
        if (m > 0)
            up = grid[m][n] + memoization(grid, dp, row, column, m - 1, n);
        if (n > 0)
            left = grid[m][n] + memoization(grid, dp, row, column, m, n - 1);
        dp[m][n] = min(up, left);
        return dp[m][n];
    }
    int tabulation(vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int row = grid.size(), column = grid[0].size(), up = INT_MAX,
            left = INT_MAX;
        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 && j == 0)
                    continue;
                else {
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                    up = INT_MAX, left = INT_MAX;
                }
            }
        }
        return dp[row - 1][column - 1];
    }
    int spaceOptimized(vector<vector<int>>& grid){
        int row = grid.size(), column = grid[0].size(), up = INT_MAX, left = INT_MAX;
        vector<int> prev(column, 0);
        for(int i=0;i<row;i++){
            vector<int> curr(column, 0);
            for(int j=0;j<column;j++){
                if(i == 0 && j == 0)
                    curr[j] = grid[i][j];
                else{
                    if(i > 0)
                        up = grid[i][j] + prev[j];
                    if(j > 0)
                        left = grid[i][j] + curr[j-1];
                    curr[j] = min(up, left);
                    up = INT_MAX, left = INT_MAX;
                }
            }
            prev = curr;
        }
        return prev[column-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), column = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(column, INT_MAX));
        // return memoization(grid, dp, row, column, row-1, column-1);
        // return tabulation(grid, dp);
        return spaceOptimized(grid);
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> gird(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>gird[i][j];
        }
    }
    Solution sol;
    cout<<sol.minPathSum(gird);
    return 0;
}