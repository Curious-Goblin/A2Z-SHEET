#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    // O(2n)
        int numberOfSubstrings(string s) {
            vector<int> countChars(3, 0);
            int count = 0, left = 0;
            
            for (int right = 0; right < s.size(); right++) {
                countChars[s[right] - 'a']++;
                
                while (countChars[0] > 0 && countChars[1] > 0 && countChars[2] > 0) {
                    count += s.size() - right;
                    countChars[s[left] - 'a']--;
                    left++;
                }
            }
            
            return count;
        }
    };

int main(){
    string s;
    cin>>s;
    Solution solve;
    cout<<solve.numberOfSubstrings(s);
    return 0;
}