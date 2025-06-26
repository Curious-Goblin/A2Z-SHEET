#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int memoization(vector<vector<int>>& matrix, vector<vector<int>>& dp, int &row, int &col, int m, int n){
        if(m == row-1) return matrix[m][n];
        if(dp[m][n] != INT_MAX) return dp[m][n];
        int down = INT_MAX, diag1 = INT_MAX, diag2 = INT_MAX;
        down = matrix[m][n] + memoization(matrix, dp, row, col, m+1, n);
        if(n>0) diag1 = matrix[m][n] + memoization(matrix, dp, row, col, m+1, n-1);
        if(n<col-1) diag2 = matrix[m][n] + memoization(matrix, dp, row, col, m+1, n+1);
        dp[m][n]= min(down, min(diag1, diag2));
        return dp[m][n];
    }
    int tabulation(vector<vector<int>>& matrix, vector<vector<int>>& dp, int& row, int& col){
        for(int i=0;i<col;i++){
            dp[row-1][i] = matrix[row-1][i];
        }
        int down = INT_MAX, diag1 = INT_MAX, diag2 = INT_MAX;
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<col;j++){
                down = matrix[i][j] + dp[i+1][j];
                if(j>0) diag1 = matrix[i][j] + dp[i+1][j-1];
                if(j<col-1) diag2 = matrix[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, min(diag1,diag2));
                down = INT_MAX, diag1 = INT_MAX, diag2 = INT_MAX;
            }
        }
        int result = INT_MAX;
        for(int i=0;i<col;i++){
            result = min(result, dp[0][i]);
        }
        return result;
    }
    int spaceOptimized(vector<vector<int>>& matrix, int& row, int& col){
        vector<int> prev(col,0);
        for(int i=0;i<col;i++){
            prev[i] = matrix[row-1][i];
        }
        int down = INT_MAX, diag1 = INT_MAX, diag2 = INT_MAX;
        for(int i=row-2;i>=0;i--){
            vector<int> curr(col,0);
            for(int j=0;j<col;j++){
                down = matrix[i][j] + prev[j];
                if(j>0) diag1 = matrix[i][j] + prev[j-1];
                if(j<col-1) diag2 = matrix[i][j] + prev[j+1];
                curr[j] = min(down, min(diag1, diag2));
                down = INT_MAX, diag1 = INT_MAX, diag2 = INT_MAX;
            }
            prev = curr;
        }
        int result = INT_MAX;
        for(int i=0;i<col;i++){
            result = min(result, prev[i]);
        }
        return result;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        // vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        // int result = INT_MAX;
        // for(int i=0;i<col;i++){
        //     result = min(result, memoization(matrix, dp, row, col, 0, i));
        // }
        // return result;
        // return tabulation(matrix, dp, row, col);
        return spaceOptimized(matrix, row, col);
    }
};

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    Solution sol;
    cout<<sol.minFallingPathSum(matrix);
    return 0;
}