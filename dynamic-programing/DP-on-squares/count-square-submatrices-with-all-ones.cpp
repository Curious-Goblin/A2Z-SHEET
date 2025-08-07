#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // tabulation
        int row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> dp(row, vector<int>(column, 0));
        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = matrix[i][j];
                        sum += matrix[i][j];
                    } else {
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                        sum += dp[i][j];
                    }
                }
            }
        }
        return sum;
    }
};

int main(){
    int rows, columns;
    cin>>rows>>columns;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cin>>matrix[i][j];
        }
    }
    Solution sol;
    cout<<sol.countSquares(matrix);
    return 0;
}