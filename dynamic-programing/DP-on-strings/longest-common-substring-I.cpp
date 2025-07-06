#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int tabulation(string text1, string text2, vector<vector<int>> &dp){
        int s1 = text1.size(), s2 = text2.size(), length = 0;
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    length = max(length, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return length;
    }
    int longestCommonSubstr(string& s1, string& s2) {
        int len1 = s1.size(), len2 = s2.size();
        vector<vector<int>> dp(len1+1, vector<int>(len2 + 1,0));
        return tabulation(s1, s2, dp);
    }
};

int main(){
    string s,a;
    cin>>s>>a;
    Solution sol;
    cout<<sol.longestCommonSubstr(s,a);
    return 0;
}