#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int tabulation(vector<int>& arr, vector<vector<int>>& dp, int sum){
        int n = arr.size();

        for(int i=0;i<n;i++) dp[i][0] = 1;
        if(arr[0] <= sum) dp[0][arr[0]] += 1;
        if(arr[0] = 0) dp[0][0] = 2;

        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){
                int notPick = dp[i-1][target];
                int pick = 0;
                if(target>=arr[i]){
                    pick = dp[i-1][target-arr[i]];
                }
                dp[i][target] = (pick + notPick);
            }
        }
        
        return dp[n-1][sum];
    }
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        return tabulation(arr, dp, target);
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.perfectSum(nums, k);
    return 0;
}