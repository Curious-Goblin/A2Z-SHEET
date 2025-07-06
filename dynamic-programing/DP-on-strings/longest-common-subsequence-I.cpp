#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(string text1, string text2, int id1, int id2){
        if(id1 < 0 || id2 < 0) return 0;
        if(text1[id1] == text2[id2]){
            return 1 + recursion(text1, text2, id1-1, id2-1);
        }
        return max(recursion(text1, text2, id1-1, id2), recursion(text1, text2, id1, id2-1));
    }
    int memoization(string text1, string text2, int id1, int id2, vector<vector<int>> &dp){
        if(id1 < 0 || id2 < 0) return 0;

        if(dp[id1][id2]!=0) return dp[id1][id2];

        if(text1[id1] == text2[id2]){
            return dp[id1][id2] = 1 + memoization(text1, text2, id1-1, id2-1, dp);
        }
        return dp[id1][id2] = max(memoization(text1, text2, id1-1, id2, dp), memoization(text1, text2, id1, id2-1, dp));
    }
    int tabulation(string text1, string text2, vector<vector<int>> &dp){
        int s1 = text1.size(), s2 = text2.size();
        for(int i=0;i<=s1;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=s2;j++){
            dp[0][j] = 0;
        }
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
    }
    int spaceOptimized(string text1, string text2){
        int s1 = text1.size(), s2 = text2.size();
        vector<int> prev(s2+1,0), curr(s2+1,0);
        prev[0] = curr[0] = 0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[s2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        // return recursion(text1, text2, s1-1, s2-1);
        // vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1,0));
        // return memoization(text1, text2, s1-1, s2-1, dp);
        // return tabulation(text1, text2, dp);
        return spaceOptimized(text1, text2);
    }
};

int main(){
    string text1, text2;
    cin>>text1>>text2;
    Solution sol;
    cout<<sol.longestCommonSubsequence(text1, text2);
    return 0;
}