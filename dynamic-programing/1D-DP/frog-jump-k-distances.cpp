#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int memoization(vector<int> &height, vector<int> &dp, int k, int index){
        if(index == 0) return 0;
        if(dp[index] != INT_MAX) return dp[index];
        for(int i=1;i<=k;i++){
            if(index-i >=0){
                dp[index] = min(dp[index], memoization(height, dp, k, index-i) + abs(height[index] - height[index-i]));
            }
        }
        return dp[index];
    }
    int tabulation(vector<int> &height, vector<int> &dp, int k){
        dp[0] = 0;
        for(int i=1;i<height.size();i++){
            for(int j=1;j<=k;j++){
                if(i-j >= 0){
                    dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
                }
            }
        }
        return dp[height.size() - 1];
    }
    int frogJump(vector<int> &height, int k){
        vector<int> dp(height.size(), INT_MAX);
        return memoization(height, dp, k, height.size()-1);
        // return tabulation(height, dp, k);
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    Solution sol;
    cout<<sol.frogJump(height, k);
    return 0;
}