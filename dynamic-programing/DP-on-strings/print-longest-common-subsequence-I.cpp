#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    void tabulation(string text1, string text2, vector<vector<int>> &dp){
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
    }
    set<string> allSequences(string text1, string text2, int i, int j, vector<vector<int>> &dp){
        if(i==0 || j==0) return {""};

        if(text1[i-1] == text2[j-1]){
            set<string> prev = allSequences(text1, text2, i-1, j-1, dp);
            set<string> result;
            for(auto s:prev) result.insert(s+text1[i-1]);
            return result;
        }

        set<string> result;
        if(dp[i-1][j] >= dp[i][j-1]){
            set<string> top = allSequences(text1, text2, i-1, j, dp);
            result.insert(top.begin(), top.end());
        }
        if(dp[i][j-1] >= dp[i-1][j]){
            set<string> left = allSequences(text1, text2, i, j-1, dp);
            result.insert(left.begin(), left.end());
        }
        return result;
    }
    set<string> allSequencesMemo(string text1, string text2, int i, int j, vector<vector<int>> &dp, vector<vector<set<string>>> &dp2){
        if(i==0 || j==0) return dp2[i][j];
        if(!dp2[i][j].empty()) return dp2[i][j];
        if(text1[i-1] == text2[j-1]){
            set<string> prev = allSequences(text1, text2, i-1, j-1, dp);
            set<string> result;
            for(auto s:prev) result.insert(s+text1[i-1]);
            return dp2[i][j] = result;
        }

        set<string> result;
        if(dp[i-1][j] >= dp[i][j-1]){
            set<string> top = allSequences(text1, text2, i-1, j, dp);
            result.insert(top.begin(), top.end());
        }
        if(dp[i][j-1] >= dp[i-1][j]){
            set<string> left = allSequences(text1, text2, i, j-1, dp);
            result.insert(left.begin(), left.end());
        }
        return dp2[i][j] = result;
    }
    set<string> allSequencesTab(string text1, string text2, vector<vector<int>> &dp, vector<vector<set<string>>> &dp2){
        int s1 = text1.size(), s2 = text2.size();
        for(int i=0;i<=s1;i++) dp2[i][0].insert("");
        for(int j=0;j<=s2;j++) dp2[0][j].insert("");
        for(int i=1;i<=s1;i++){
            for(int j=1;j<=s2;j++){
                if(text1[i-1] == text2[j-1]){
                    for(auto &s:dp2[i-1][j-1]){
                        dp2[i][j].insert(s+text1[i-1]);
                    }
                }
                else{
                    if(dp[i][j-1] > dp[i-1][j]){
                        dp2[i][j] = dp2[i][j-1];
                    }
                    else if(dp[i-1][j] > dp[i][j-1]){
                        dp2[i][j] = dp2[i-1][j];
                    }
                    else{
                        dp2[i][j] = dp2[i][j-1];
                        dp2[i][j].insert(dp2[i-1][j].begin(), dp2[i-1][j].end());
                    }
                }
            }
        }
        return dp2[s1][s2];
    }
    vector<string> allLCS(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0)); 
        tabulation(s1, s2, dp);
        vector<vector<set<string>>> dp2(n+1, vector<set<string>>(m+1));
        // set<string> result = allSequences(s1, s2, n, m, dp);
        // set<string> result = allSequencesMemo(s1, s2, n, m, dp, dp2);
        set<string> result = allSequencesTab(s1, s2, dp, dp2);
        vector<string> ans;
        for(auto &s:result) ans.push_back(s);
        return ans;    
    }
};

int main(){
    string text1, text2;
    cin>>text1>>text2;
    Solution sol;
    vector<string> result = sol.allLCS(text1, text2);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}