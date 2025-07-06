#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(string &s, string &t, int id1, int id2){
        if(id2<0) return 1;
        if(id1<0) return 0;
        if(s[id1] == t[id2]){
            return recursion(s, t, id1-1, id2-1) + recursion(s, t, id1-1, id2);
        }
        else return recursion(s, t, id1-1, id2);
    }
    int memoization(string &s, vector<vector<int>> &dp, string &t, int id1, int id2){
        if(id2<0) return 1;
        if(id1<0) return 0;
        if(dp[id1][id2]!=-1) return dp[id1][id2];
        if(s[id1] == t[id2]){
            return dp[id1][id2] = memoization(s, dp, t, id1-1, id2-1) + memoization(s, dp, t, id1-1, id2);
        }
        else return dp[id1][id2] = memoization(s, dp, t, id1-1, id2);
    }
    int tabulation(string &s, string &t, vector<vector<int>> &dp){
        int n = s.size(), m = t.size();
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
    int spaceOptimized(string &s, string &t){
        int n = s.size(), m = t.size();
        vector<unsigned long long> prev(m+1, 0),curr(m+1,-1);
        prev[0] = curr[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1] + prev[j];
                }
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return prev[m];
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // return recursion(s, t, n-1, m-1);
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return memoization(s, dp, t, n-1, m-1);
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return tabulation(s, t, dp);
        return spaceOptimized(s, t);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    Solution sol;
    cout<<sol.numDistinct(s,t);
    return 0;
}