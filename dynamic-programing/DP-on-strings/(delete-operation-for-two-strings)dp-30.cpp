#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
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
    int minDistance(string word1, string word2) {
        int len = spaceOptimized(word1, word2);
        int size1 = word1.size(), size2 = word2.size();
        int result = size1 + size2 - len - len;
        return result;
    }
};

int main(){
    string s,a;
    cin>>s>>a;
    Solution sol;
    cout<<sol.minDistance(s, a);
    return 0;
}