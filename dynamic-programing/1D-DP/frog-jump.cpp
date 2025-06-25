#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int memoization(vector<int> &height, vector<int> &dp, int index){
        if(index == 0) return 0;
        if(dp[index] != -1) return dp[index];

        int left = memoization(height, dp, index - 1) + abs(height[index] - height[index-1]);
        int right = INT_MAX;
        if(index > 1) right = memoization(height, dp, index - 2) + abs(height[index] - height[index-2]);
        return dp[index] = min(left, right);
    }
    int tabulation(vector<int> &height){
        int prev = 0, prev2 = 0, curr = 0;
        for(int i=1;i<height.size();i++){
            int left = prev + abs(height[i]-height[i-1]);
            int right = INT_MAX;
            if(i>1) right = prev2 + abs(height[i]-height[i-2]);
            curr = min(left, right);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int minCost(vector<int> &height){
        vector<int> dp(height.size(),-1);
        return memoization(height, dp, height.size()-1);
        // int result = tabulation(height);
        // return result;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    Solution sol;
    cout<<sol.minCost(height);
    return 0;
}