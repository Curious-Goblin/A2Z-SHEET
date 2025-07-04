#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int recursion(vector<int>& val, vector<int>& wt, int capacity, int index){
        if(index == 0){
            int take = 0;
            if (wt[0] <= capacity) {
                take = val[0] + recursion(val, wt, capacity - wt[0], 0);
            }
            int skip = 0;
            return max(skip, take);
        }
        int skip = recursion(val, wt, capacity, index-1);
        int take = 0;
        if(wt[index] <= capacity){
            take = val[index] + recursion(val, wt, capacity-wt[index], index);
        }
        return max(skip,take);
    }
    int memoization(vector<int>& val,vector<int>& wt, vector<vector<int>>& dp, int capacity, int index){
        if(index == 0){
            int take = 0;
            if (wt[0] <= capacity) {
                take = val[0] + memoization(val, wt, dp, capacity - wt[0], 0);
            }
            int skip = 0;
            return max(skip, take);
        }
        if(dp[index][capacity] != 0) return dp[index][capacity];
        int skip = memoization(val, wt, dp, capacity, index-1);
        int take = 0;
        if(wt[index] <= capacity){
            take = val[index] + memoization(val, wt, dp, capacity-wt[index], index);
        }
        return dp[index][capacity] = max(skip,take);
    }
    int tabulation(vector<int>& val, vector<int>& wt, vector<vector<int>>& dp, int capacity){
        int n = val.size();
        for(int i=1;i<=capacity;i++){
            if(wt[0] <= i){
                dp[0][i] = val[0] + dp[0][i-wt[0]];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=capacity;j++){
                int skip = dp[i-1][j];
                int take = 0;
                if(wt[i] <= j){
                    take = dp[i][j - wt[i]] + val[i];
                }
                dp[i][j] = max(skip, take);
            }
        }
        return dp[n-1][capacity];
    }
    int spaceOptimized(vector<int>& val, vector<int>& wt, int capacity){
        int n = val.size();
        vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);
        for(int i=1;i<=capacity;i++){
            if(wt[0] <= i){
                prev[i] = val[0] + prev[i-wt[0]];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=capacity;j++){
                int skip = prev[j];
                int take = 0;
                if(wt[i] <= j){
                    take = curr[j-wt[i]] + val[i];
                }
                curr[j] = max(skip, take);
            }
            prev = curr;
        }
        return prev[capacity];
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        // return recursion(val, wt, capacity, n-1);
        // vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        // return memoization(val, wt, dp, capacity, n-1);
        // return tabulation(val, wt, dp, capacity);
        return spaceOptimized(val, wt, capacity);
    }
};

int main(){
    int capacity, n;
    cin>>capacity>>n;
    vector<int> val(n), wt(n);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    Solution sol;
    cout<<sol.knapSack(val, wt, capacity);
    return 0;
}