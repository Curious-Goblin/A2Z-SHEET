#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
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
    int minInsertions(string s) {
        int n = s.size();
        // vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        int len = spaceOptimized(s);
        return n - len;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sol;
    cout<<sol.minInsertions(s);
    return 0;
}