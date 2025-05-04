#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    // O(2n)
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0, right = 0, length = 0;
        while(right < s.size()){
            if(map.find(s[right])!=map.end()){
                length = max(right-left,length);
                while(s[left]!=s[right]){
                    map.erase(s[left]);
                    left++;
                }
                map.erase(s[left]);
                left++;
            }
            map.insert({s[right],1});
            right++;
        }
        length = max(length, right-left);
        return length;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solve;
    cout<<solve.lengthOfLongestSubstring(s);
    return 0;
}