#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    // this is an incorrect logic we should check every word from the worddict at every point in the string
    // void helper(string s, vector<string> &wordDict, int index, bool &result, int wordIndex){
    //     if(index == s.size()){
    //         result = true;
    //         return;
    //     }
    //     string subPart = s.substr(index, wordDict[wordIndex].size());
    //     if(subPart == wordDict[wordIndex]){
    //         helper(s, wordDict, index + wordDict[wordIndex].size(), result, wordIndex);
    //     }
    //     else{
    //         if(wordIndex == wordDict.size()-1){
    //             helper(s, wordDict, index, result, 0);
    //         }
    //         else{
    //             helper(s, wordDict, index, result, wordIndex+1);
    //         }
    //     }
    // }

    // time complexity = O(n*k*m) n = length of string, k = size of wordDict and k = max length of word in worddict
    // space = O(n) memo + O(n) call stack
    bool helper(string s, vector<string> &wordDict, unordered_map<int, bool> &memo, int index){
        if(index == s.size()){
            return true;
        }
        if(memo.find(index)!= memo.end()) return memo[index];

        for(string &word : wordDict){
            int len = word.size();
            // this check takes O(len) time
            if(index + len <= s.size() && s.substr(index, len) == word ){
                if(helper(s, wordDict, memo, index + len)){
                    return memo[index] = true;
                }
            }
        }
        return memo[index] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_map<int, bool> memo;
        return helper(s, wordDict, memo, 0);
        
    }
};

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string> wordDict(n);
    for(int i=0;i<n;i++){
        cin>>wordDict[i];
    }
    Solution solve;
    bool result = solve.wordBreak(s, wordDict);
    cout<<result;
    return 0;
}