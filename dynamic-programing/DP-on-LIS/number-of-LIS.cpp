#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1), count(n,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    if(dp[prev] + 1 > dp[i]){
                        dp[i] = dp[prev] + 1;
                        count[i] = count[prev];
                    }
                    else if(dp[prev] + 1 == dp[i]){
                        count[i] += count[prev];
                    }
                }
            }
            res = max(dp[i], res);
        }

        int maxi = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == res){
                maxi += count[i];
            }
        }
        return maxi;
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
    cout<<sol.findNumberOfLIS(nums);
    return 0;
}