#include "bits/stdc++.h"

using namespace std;

class Solution {
    public:
    // O(N*M)
        string minWindow(string s1, string s2) {
            int n = s1.size(), m = s2.size();
            int minLen = INT_MAX, startIdx = -1;
    
            for (int i = 0; i < n; ++i) {
                if (s1[i] != s2[0]) continue;
                int j = 0, k = i;
                while (k < n && j < m) {
                    if (s1[k] == s2[j]) j++;
                    k++;
                }
                if (j == m) {
                    // Now backtrack from k-1 to find the minimal window
                    int end = k - 1;
                    j = m - 1;
                    while (end >= i) {
                        if (s1[end] == s2[j]) j--;
                        if (j < 0) break;
                        end--;
                    }
                    int windowLen = k - end;
                    if (windowLen < minLen) {
                        minLen = windowLen;
                        startIdx = end;
                    }
                }
            }
    
            return startIdx == -1 ? "" : s1.substr(startIdx, minLen);
        }
    };
    

int main(){
    string s1,s2;
    cin>>s1>>s2;
    Solution solve;
    cout<<solve.minWindow(s1, s2);
    return 0;
}