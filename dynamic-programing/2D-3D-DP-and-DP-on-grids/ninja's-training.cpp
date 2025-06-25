#include "bits/stdc++.h"

using namespace std;

class Solution{
public:
    int memoization(vector<vector<int>>& arr,vector<vector<int>>& dp, int index, int last){
        if(index == 0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i != last) maxi = max(maxi, arr[0][i]);
            }
            return maxi;
        }
        if(dp[index][last] != -1) return dp[index][last];
        int maxi = 0, points = 0;
        for(int i=0;i<3;i++){
            if(i != last) {
                points = arr[index][i] + memoization(arr, dp, index-1, i);
                maxi = max(maxi, points);
            }
        }
        return dp[index][last] = maxi;
    }
    int tabulation(vector<vector<int>> &arr, vector<vector<int>> &dp){
        vector<int> prev(4);
        prev[0] = max(arr[0][1],arr[0][2]);
        prev[1] = max(arr[0][0],arr[0][2]);
        prev[2] = max(arr[0][1],arr[0][0]);
        prev[3] = max(arr[0][1], max(arr[0][2],arr[0][0]));  

        int curri = 0;
        for(int i=1;i<arr.size();i++){
            vector<int> temp(4, 0);
            for(int j=0;j<=3;j++){
                temp[j] = 0;
                for(int k=0;k<3;k++){
                    if(k!=j){
                        temp[j] = max(temp[j], arr[i][k] + prev[k]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        // return memoization(arr, dp, n-1, 3);
        return tabulation(arr, dp);
    }
}; 

int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n, vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    Solution sol;
    cout<<sol.maximumPoints(nums);
    return 0;
}