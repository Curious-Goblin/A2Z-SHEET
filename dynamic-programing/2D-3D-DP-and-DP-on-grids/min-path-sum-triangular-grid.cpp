#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int memoization(vector<vector<int>>& triangle, vector<vector<int>>& dp, int m, int n){
        if(m == triangle.size()-1) return triangle[m][n];
        if(dp[m][n] != INT_MAX) return dp[m][n];
        int down = INT_MAX, diag = INT_MAX;
        down = triangle[m][n] + memoization(triangle, dp, m+1,n);
        diag = triangle[m][n] + memoization(triangle, dp, m+1, n+1);
        dp[m][n] = min(down, diag);
        return dp[m][n];
    }
    int tabulation(vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n = triangle.size(), down = INT_MAX, diag = INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++){  
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                down = triangle[i][j] + dp[i+1][j];
                diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
    int spaceOptimized(vector<vector<int>>& triangle){
        int n = triangle.size(), down = INT_MAX, diag = INT_MAX;
        vector<int> prev(n,0);
        for(int i=0;i<triangle[n-1].size();i++){  
            prev[i] = triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=i;j>=0;j--){
                down = triangle[i][j] + prev[j];
                diag = triangle[i][j] + prev[j+1];
                curr[j] = min(down, diag);
            }
            prev = curr;
        }
        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for(int i=0;i<n;i++){
            int size = triangle[i].size();
            vector<int> temp(size, INT_MAX);
            dp[i] = temp;
        }
        // return memoization(triangle, dp, 0, 0);
        // return tabulation(triangle, dp);
        return spaceOptimized(triangle);
    }
};

int main(){
    int n;
    cin>>n;
    vector<vector<int>> triangle(n);
    for(int i=0;i<n;i++){
        vector<int> temp(i+1);
        for(int j=0;j<(i+1);j++){
            cin>>temp[j];
        }
        triangle[i] = temp;
    }
    Solution sol;
    cout<<sol.minimumTotal(triangle);
    return 0;
}