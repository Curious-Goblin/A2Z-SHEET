#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(string &s, int id1, int id2){
        if(id1 > id2) return 0;
        if(id1 == id2){
            if(s[id1] == s[id2]) return 1;
            return 0;
        }
        if(s[id1] == s[id2]){
            return 2 + recursion(s, id1+1, id2-1);
        }
        return max(recursion(s, id1+1, id2), recursion(s, id1, id2-1));
    }
    int memoization(string &s, vector<vector<int>> &dp, int id1, int id2){
        if(id1 > id2) return 0;
        if(id1 == id2){
            if(s[id1] == s[id2]) return 1;
            return 0;
        }
        if(dp[id1][id2] != 0) return dp[id1][id2];
        if(s[id1] == s[id2]){
            return dp[id1][id2] = 2 + memoization(s, dp, id1+1, id2-1);
        }
        return dp[id1][id2] = max(memoization(s, dp, id1+1, id2), memoization(s, dp, id1, id2-1));
    }
    int tabulation(string &s, vector<vector<int>> &dp){
        int n = s.size();
        for(int i = n - 1; i >= 0; --i){
            dp[i][i] = 1;
            for(int j = i + 1; j < n; ++j){
                if(s[i] == s[j]){
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
    int spaceOptimized(string &s){
        int n = s.size();
        vector<int> curr(n,0), next(n,0);
        for(int i=n-1;i>=0;--i){
            curr[i] = 1;
            for(int j=i+1;j<n;++j){
                if(s[i]==s[j]){
                    curr[j] = 2 + next[j-1];
                } 
                else{
                    curr[j] = max(next[j], curr[j-1]);
                }
            }
            next = curr;
        }
        return curr[n-1];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // return recursion(s, 0, n-1);
        vector<vector<int>> dp(n,vector<int>(n,0));
        // return memoization(s, dp, 0, n-1);
        // return tabulation(s, dp);
        return spaceOptimized(s);
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.longestPalindromeSubseq(s);
    return 0;
}