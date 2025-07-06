#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(string &s, string &t, int id1, int id2){
        if(id2 < 0) return id1 + 1;
        if(id1 < 0) return id2 + 1;
        if(s[id1] == t[id2]) return 0 + recursion(s, t, id1-1, id2-1);
        else {
            return 1 + min(recursion(s, t, id1, id2-1), min(recursion(s, t, id1-1, id2), recursion(s, t, id1-1, id2-1)));
        }
    }
    int memoization(string &s, string &t, vector<vector<int>> &dp, int id1, int id2){
        if(id2 < 0) return id1 + 1;
        if(id1 < 0) return id2 + 1;
        if(dp[id1][id2] != -1) return dp[id1][id2];
        if(s[id1] == t[id2]) return dp[id1][id2] = 0 + memoization(s, t, dp, id1-1, id2-1);
        else {
            return dp[id1][id2] = 1 + min(memoization(s, t, dp, id1, id2-1), min(memoization(s, t, dp, id1-1, id2), memoization(s, t, dp, id1-1, id2-1)));
        }
    }
    int tabulation(string &s, string &t, vector<vector<int>> &dp){
        int n = s.size(), m = t.size();
        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
            }
        }
        return dp[n][m];
    }
    int spaceOptimized(string &s, string &t){
        int n = s.size(), m = t.size();
        vector<unsigned long long> prev(m+1, 0),curr(m+1,0);
        for(int j=0;j<=m;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n;i++){
            curr[0] = i;
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    curr[j] = prev[j-1];
                }
                else curr[j] = 1 + min(prev[j],min(curr[j-1], prev[j-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // return recursion(word1, word2, n-1, m-1);
        // vector<vector<int>> dp(n, vector<int>(m,-1));
        // return memoization(word1, word2, dp, n-1, m-1);
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return tabulation(word1, word2, dp);
        return spaceOptimized(word1, word2);
    }
};

int main(){
    string s, t;
    cin>>s>>t;
    Solution sol;
    cout<<sol.minDistance(s,t);
    return 0;
}