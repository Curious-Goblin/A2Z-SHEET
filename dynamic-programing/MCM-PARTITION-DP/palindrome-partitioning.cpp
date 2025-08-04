#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    int recursion(string &s, int start){
        if(start >= s.length()) return 0;
        int count = 0, minCount = 1e9;
        for(int i = start; i < s.length(); i++){
            if(checkPalindrome(s, start, i)){
                count = 1 + recursion(s, i+1);
                minCount = min(minCount, count);
            }
        }
        return minCount;
    }
    int memoization(string &s, int start, vector<int> &dp){
        if(start >= s.length()) return 0;
        if(dp[start] != -1) return dp[start];
        int count = 0, minCount = 1e9;
        for(int i = start; i < s.length(); i++){
            if(checkPalindrome(s, start, i)){
                count = 1 + memoization(s, i+1, dp);
                minCount = min(minCount, count);
            }
        }
        return dp[start] = minCount;
    }
    int tabulation(string &s, vector<int> &dp){
        int n = s.length();

        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - i <= 2) {
                        isPalindrome[i][j] = true;
                    } else {
                        isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    }
                }
            }
        }

        for(int i = n - 1; i >= 0; i--){
            int minCuts = 1e9;
            for(int j = i; j < n; j++){
                if(isPalindrome[i][j]){
                    int cuts = 1;
                    if(j+1 < n){
                        cuts += dp[j+1];
                    }
                    minCuts = min(minCuts, cuts);
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
    int minCut(string s) {
        if(checkPalindrome(s, 0, s.length()-1)) return 0;
        int length = s.size();
        // return recursion(s, 0)-1;
        // vector<int> dp(length, -1);
        // return memoization(s, 0, dp)-1;
        vector<int> dp(length, 0);
        return tabulation(s, dp)-1;
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution sol;
    cout<<sol.minCut(s);
    return 0;
}