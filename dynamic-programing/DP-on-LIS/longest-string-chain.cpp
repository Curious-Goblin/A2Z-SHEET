#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkPossible(string &s1, string &s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while(first < s1.size()) {
            if(second < s2.size() && s1[first] == s2[second]){
                first++, second++;
            }
            else{
                first++;
            }
        }
        if(first == s1.size() && second == s2.size()) return true;
        return false;
    }
    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n,1);
        int res = 1;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(checkPossible(words[i], words[prev])){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    Solution sol;
    cout<<sol.longestStrChain(words);
    return 0;
}