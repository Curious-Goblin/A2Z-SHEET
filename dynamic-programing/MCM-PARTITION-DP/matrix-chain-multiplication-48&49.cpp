#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int recursion(vector<int> &arr, int start, int end){
        if(start == end) return 0;

        int minSteps = 1e9,steps=0;
        for(int k = start; k < end; k++){
            steps = (arr[start - 1] * arr[k] * arr[end]) + recursion(arr, start, k) + recursion(arr, k+1, end);
            minSteps = min(minSteps, steps); 
        }
        return minSteps;
    }
    int memoization(vector<int> &arr, vector<vector<int>> &dp, int start, int end){
        if(start == end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int minSteps = 1e9,steps=0;
        for(int k = start; k < end; k++){
            steps = (arr[start - 1] * arr[k] * arr[end]) + memoization(arr, dp, start, k) + memoization(arr, dp, k+1, end);
            minSteps = min(minSteps, steps); 
        }
        return dp[start][end] = minSteps;
    }
    int tabulation(vector<int> &arr, vector<vector<int>> &dp){
        int n = arr.size();
        for(int i=1;i<n;i++){
            dp[i][i] = 0;
        }
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int minSteps = 1e9, steps = 0;
                for(int k = i; k < j; k++){
                    steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
                    minSteps = min(minSteps, steps);
                }
                dp[i][j] = minSteps;
            }
        }
        return dp[1][n-1];
    }
    int matrixMultiplication(vector<int> &arr){
        int n = arr.size();
        // return recursion(arr, 1, n-1);
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memoization(arr, dp, 1, n-1);
        return tabulation(arr, dp);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.matrixMultiplication(nums);
    return 0;
}