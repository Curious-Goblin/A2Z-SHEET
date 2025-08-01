// https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int recursion(string &s, int start, int end, int isTrue){
        if(start == end){
            if(isTrue == 1) return s[start] == 'T';
            else return s[start] == 'F';
        }
        if(start > end) return 0;
        int ways = 0;
        for(int i = start + 1; i <= end-1; i = i + 2){
            int lt = recursion(s, start, i-1, 1);
            int lf = recursion(s, start, i-1, 0);
            int rt = recursion(s, i + 1, end, 1); 
            int rf = recursion(s, i + 1, end, 0); 

            if(s[i] == '&') {
                if(isTrue) ways += lt * rt;
                else ways += lf*rf + lt*rf + lf*rt;
            }
            if(s[i] == '|') {
                if(isTrue) ways += lt*rt + lt*rf + lf*rt;
                else ways += lf*rf;
            }
            if(s[i] == '^'){
                if(isTrue) ways += lt*rf + lf*rt;
                else ways += lt*rt + lf*rf;
            }
        }
        
        return ways;
    }
    int memoization(string &s, int start, int end, int isTrue, vector<vector<vector<int>>> &dp){
        if(start == end){
            if(isTrue == 1) return s[start] == 'T';
            else return s[start] == 'F';
        }
        if(start > end) return 0;

        if(dp[start][end][isTrue] != -1) return dp[start][end][isTrue];
        int ways = 0;
        for(int i = start + 1; i <= end-1; i = i + 2){
            int lt = memoization(s, start, i-1, 1, dp);
            int lf = memoization(s, start, i-1, 0, dp);
            int rt = memoization(s, i + 1, end, 1, dp); 
            int rf = memoization(s, i + 1, end, 0, dp); 

            if(s[i] == '&') {
                if(isTrue) ways += lt * rt;
                else ways += lf*rf + lt*rf + lf*rt;
            }
            if(s[i] == '|') {
                if(isTrue) ways += lt*rt + lt*rf + lf*rt;
                else ways += lf*rf;
            }
            if(s[i] == '^'){
                if(isTrue) ways += lt*rf + lf*rt;
                else ways += lt*rt + lf*rf;
            }
        }
        
        return dp[start][end][isTrue] = ways;
    }
    int countWays(string &s) {
        int n = s.size();
        // return recursion(s, 0, n-1, 1);
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
        // return memoization(s, 0, n-1, 1, dp);
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.countWays(s);
    return 0;
}