#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // O(2n)
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, length = 0, maxFreq = 0;
        unordered_map<char,int> map;
        while(right<s.size()){
            map[s[right]]++;
            maxFreq = max(maxFreq, map[s[right]]);
            while(right-left+1-maxFreq>k){
                map[s[left]]--;
                left++;
            }
            length = max(length, right-left + 1);
            right++;
        }
        return length;
    }
};

int main(){
    string s;
    int k;
    cin>>s>>k;
    Solution solve;
    cout<<solve.characterReplacement(s,k);
    return 0;
}