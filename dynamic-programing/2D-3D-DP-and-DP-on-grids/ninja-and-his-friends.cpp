#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursive(vector<vector<int>>& grid, int& row, int& col, int m, int n1,
                  int n2) {
        if (m == row - 1) {
            if (n1 == n2)
                return grid[m][n1];
            else {
                return grid[m][n1] + grid[m][n2];
            }
        }
        int maxi = -1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (n1 == n2) {
                    if (n1 + i >= 0 && n2 + j >= 0 && n1 + i < col &&
                        n2 + j < col) {
                        maxi = max(maxi, grid[m][n1] + recursive(grid, row, col,
                                                                 m + 1, n1 + i,
                                                                 n2 + j));
                    }
                } else {
                    if (n1 + i >= 0 && n2 + j >= 0 && n1 + i < col &&
                        n2 + j < col) {
                        maxi = max(maxi, grid[m][n1] + grid[m][n2] +
                                             recursive(grid, row, col, m + 1,
                                                       n1 + i, n2 + j));
                    }
                }
            }
        }
        return maxi;
    }
    int memoization(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
                    int& row, int& col, int m, int n1, int n2) {
        if (m == row - 1) {
            if (n1 == n2)
                return grid[m][n1];
            else {
                return grid[m][n1] + grid[m][n2];
            }
        }
        if (dp[m][n1][n2] != -1)
            return dp[m][n1][n2];
        int maxi = -1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (n1 == n2) {
                    if (n1 + i >= 0 && n2 + j >= 0 && n1 + i < col &&
                        n2 + j < col) {
                        maxi =
                            max(maxi, grid[m][n1] +
                                          memoization(grid, dp, row, col, m + 1,
                                                      n1 + i, n2 + j));
                    }
                } else {
                    if (n1 + i >= 0 && n2 + j >= 0 && n1 + i < col &&
                        n2 + j < col) {
                        maxi =
                            max(maxi, grid[m][n1] + grid[m][n2] +
                                          memoization(grid, dp, row, col, m + 1,
                                                      n1 + i, n2 + j));
                    }
                }
            }
        }
        return dp[m][n1][n2] = maxi;
    }
    int tabulation(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp,
                   int& row, int& col) {
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                if (i == j) {
                    dp[row - 1][i][j] = grid[row - 1][i];
                } else {
                    dp[row - 1][i][j] = grid[row - 1][i] + grid[row - 1][j];
                }
            }
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    int maxi = -1e8;
                    for (int d = -1; d <= 1; d++) {
                        for (int e = -1; e <= 1; e++) {
                            int value = 0;
                            if (j == k) {
                                value = grid[i][j];
                            } else {
                                value = grid[i][j] + grid[i][k];
                            }
                            if (j + d >= 0 && k + e >= 0 && j + d < col &&
                                k + e < col) {
                                value += dp[i + 1][j + d][e + k];
                            } else {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j][k] = maxi;
                }
            }
        }
        return dp[0][0][col - 1];
    }
    int spaceOptimized(vector<vector<int>>& grid, int& row, int& col) {
        vector<vector<int>> front(col, vector<int>(col));
        vector<vector<int>> curr(col, vector<int>(col));
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                if (i == j) {
                    front[i][j] = grid[row - 1][i];
                } else {
                    front[i][j] = grid[row - 1][i] + grid[row - 1][j];
                }
            }
        }
        for (int i = row - 2; i >= 0; i--) {
            for (int j = 0; j < col; j++) {
                for (int k = 0; k < col; k++) {
                    int maxi = -1e8;
                    for (int d = -1; d <= 1; d++) {
                        for (int e = -1; e <= 1; e++) {
                            int value = 0;
                            if (j == k) {
                                value = grid[i][j];
                            } else {
                                value = grid[i][j] + grid[i][k];
                            }
                            if (j + d >= 0 && k + e >= 0 && j + d < col &&
                                k + e < col) {
                                value += front[j + d][e + k];
                            } else {
                                value += -1e8;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j][k] = maxi;
                }
            }
            front = curr;
        }
        return front[0][col - 1];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<vector<int>>> dp(
            row, vector<vector<int>>(col, vector<int>(col, -1)));
        // return recursive(grid, row, col, 0, 0, col-1);
        // return memoization(grid, dp, row, col, 0, 0, col-1);
        // return tabulation(grid, dp, row, col);
        return spaceOptimized(grid, row, col);
    }
}; 

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    Solution sol;
    cout<<sol.cherryPickup(grid);
    return 0;
}