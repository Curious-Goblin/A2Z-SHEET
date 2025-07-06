#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
bool memoization(string &s, string &p, vector<vector<bool>> &dp, int id1, int id2){
    if(id1<0 && id2<0) return true;
    if(id1 >= 0 && id2 < 0) return false;
    if(id1<0 && id2 >= 0){
        for(int i=0;i<=id2;i++){
            if(p[i] != '*') return false;
        }
        return true;
    }
    if(dp[id1][id2]!=false) return dp[id1][id2];
    if(s[id1] == p[id2] || p[id2] == '?'){
        return dp[id1][id2] = memoization(s, p, dp, id1-1, id2-1);
    }
    else if(p[id2] == '*') return dp[id1][id2] = (memoization(s, p, dp, id1-1, id2) || memoization(s, p, dp, id1, id2-1));
    
    return false;
}
bool recursion(string &s, string &p, int id1, int id2){
    if(id1<0 && id2<0) return true;
    if(id1 >= 0 && id2 < 0) return false;
    if(id1<0 && id2 >= 0){
        for(int i=0;i<=id2;i++){
            if(p[i] != '*') return false;
        }
        return true;
    }
    if(s[id1] == p[id2] || p[id2] == '?'){
        return recursion(s, p, id1-1, id2-1);
    }
    else if(p[id2] == '*') return (recursion(s, p, id1-1, id2) || recursion(s, p, id1, id2-1));

    return false;
}
    bool tabulation(string &s, string &p, vector<vector<bool>> &dp){
        int n = s.size(), m = p.size();
        dp[0][0] = true;
        // for(int i=1;i<=n;i++){
        //     dp[i][0] = false;
        // }
        for(int i=1;i<=m;i++){
            if(p[i-1] == '*'){
                dp[0][i] = dp[0][i-1];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
    bool spaceOptimized(string &s, string &p){
        int n = s.size(), m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for(int i=1;i<=m;i++){
            if(p[i-1] == '*'){
                prev[i] = prev[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            curr[0] = false;
            for(int j=1;j<=m;j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else if(p[j-1] == '*') curr[j] = (prev[j] || curr[j-1]);
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // return recursion(s, p, n-1, m-1);
        // vector<vector<bool>> dp(n, vector<bool>(m,false));
        // return memoization(s, p, dp, n-1, m-1);
        // vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        // return tabulation(s, p, dp);
        return spaceOptimized(s, p);
    }
};

int main(){
    string s,p;
    cin>>s>>p;
    Solution sol;
    cout<<sol.isMatch(s, p);
    return 0;
}