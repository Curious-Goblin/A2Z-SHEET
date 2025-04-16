#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // bool isAnagram(string s, string t)
    // {
    //     if(s.length()!=t.length()){
    //         return false;
    //     }
    //     unordered_map<char,int> characters;
    //     for(size_t i=0;i<s.size();i++){
    //         characters[s[i]]++;
    //     }
    //     for(size_t i=0;i<t.size();i++){
    //         auto it = characters.find(t[i]);
    //         if(it==characters.end()){
    //             return false;
    //         }
    //         else if(it->second > 0){
    //             it->second--;
    //         }
    //         else if(it->second == 0){
    //             return false;
    //         }
    //     }
    //     return true;
    // }


    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int freq[26] = {0};

        for (char c : s) freq[c - 'a']++;
        for (char c : t) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) return false;
        }

        return true;
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    Solution solution;
    bool result = solution.isAnagram(s, t);
    cout << result;
    return 0;
}