#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    bool memoization(vector<int>& arr, vector<vector<int>>& dp,int index, int sum){
        if(sum==0) return true;
        if(index < 0) return false;
        if(index == 0) return (arr[index] == sum);
        if(dp[index][sum] != -1) return dp[index][sum];
        bool pick = false;
        if(sum >= arr[index]){
            pick = memoization(arr, dp, index-1, sum-arr[index]);
        }
        bool skip = memoization(arr, dp, index-1, sum);
        return dp[index][sum]=(pick || skip);
    }
    int tabulation(vector<int>& arr, vector<vector<int>>& dp, int sum){
        int n = arr.size();
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        if(sum >= arr[0]){
            dp[0][arr[0]] = 1;
        }
        for(int i=1;i<n;i++){
            bool pick = false, skip = false;
            for(int target=0;target<=sum;target++){
                if(target>=arr[i]){
                    pick = dp[i-1][target-arr[i]];
                }
                skip = dp[i-1][target];
                dp[i][target] = pick || skip;
                pick = false, skip = false;
            }
        }
        return dp[n-1][sum];
    }
    bool spaceOptimized(vector<int>& arr, int& sum){
        int n = arr.size();
        vector<bool> prev(sum+1,0), curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(sum >= arr[0]) prev[arr[0]] = true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                curr[target] = prev[target] || (target >= arr[i] && prev[target-arr[i]]);
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return memoization(arr, dp, n-1, sum);
        // vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        // return tabulation(arr, dp, sum);
        return spaceOptimized(arr, sum);
    }
};

int main(){
    int n, sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution sol;
    cout<<sol.isSubsetSum(arr, sum);
    return 0;
}