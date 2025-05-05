#include "bits/stdc++.h"

using namespace std;

class Solution {
    public:
    string minWindow(string s, string t) {
        unordered_map<char,int> target;
        for(char &c:t){
            target[c]++;
        }
        int left = 0, right = 0, minLen = INT_MAX, startIdx = 0, formed = 0, required = target.size();
        unordered_map<char,int> window;
        while(right<s.size()){
            char c = s[right];
            window[c]++;
            if(target.count(c) && window[c]==target[c]){
                formed++;
            }
            while(formed == required){
                if(right-left + 1 < minLen){
                    minLen = right-left+1;
                    startIdx = left;
                }
                char l = s[left];
                window[l]--;
                if(target.count(l) && window[l]<target[l]){
                    formed--;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "":s.substr(startIdx, minLen);
    }
};

int main(){
    string s,t;
    cin>>s>>t;
    Solution solve;
    cout<<solve.minWindow(s, t);
    return 0;
}