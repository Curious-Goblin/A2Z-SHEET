#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    // O(n)
    int longestKSubstr(string &s, int k) {
        int left = 0, right = 0, length = -1;
        unordered_map<char,int> map;
        for(;right < s.size(); ++right){
            map[s[right]]++;
            if(map.size()==k){
                length = max(length, right - left + 1);
            }
            if(map.size()>k){
                while(map.size()>k){
                    map[s[left]]--;
                    if(map[s[left]] == 0){
                        map.erase(s[left]);
                    }
                    left++;
                }
            }
        }
        return length;
    }
};

int main(){
    int k;
    string s;
    cin>>s>>k;
    Solution solve;
    cout<<solve.longestKSubstr(s,k);
    return 0;
}