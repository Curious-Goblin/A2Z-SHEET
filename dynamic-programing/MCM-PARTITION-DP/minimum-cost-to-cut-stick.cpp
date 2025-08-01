#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int>& cuts, int start, int end) {
        if (start > end)
            return 0;
        int costs = 0, minCost = 1e9;
        for (int i = start; i <= end; i++) {
            costs = cuts[end + 1] - cuts[start - 1] +
                    recursion(cuts, start, i - 1) + recursion(cuts, i + 1, end);
            minCost = min(minCost, costs);
        }
        return minCost;
    }
    int memoization(vector<int>& cuts, int start, int end,
                    vector<vector<int>>& dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int costs = 0, minCost = 1e9;
        for (int i = start; i <= end; i++) {
            costs = cuts[end + 1] - cuts[start - 1] +
                    memoization(cuts, start, i - 1, dp) +
                    memoization(cuts, i + 1, end, dp);
            minCost = min(minCost, costs);
        }
        return dp[start][end] = minCost;
    }
    int minCost(int n, vector<int>& cuts) {
        int len = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
        // return recursion(cuts, 1, cuts.size());
        return memoization(cuts, 1, len, dp);
    }
};

int main(){
    int n,len;
    cin>>n>>len;
    vector< int> cuts(len);
    for( int i=0;i<len;i++){
        cin>>cuts[i];
    }
    Solution sol;
    cout<<sol.minCost(n, cuts);
    return 0;
}