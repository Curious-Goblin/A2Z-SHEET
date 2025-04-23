#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:

    // time complexity is O(2^n * n) n is for checking palidrome and creating substrings
    // space complexity is also the same n is the stack space and the other one is the
    // largest number of substirngs which could be created.

    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void helper(string s, vector<vector<string>> &result, vector<string> &path, int index){
        if(index == s.size()){
            result.push_back(path);
            return;
        }
        for(int i = index; i<s.size();++i){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i-index+1));
                helper(s, result, path, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        vector<vector<string>> result;
        vector<string> path;
        helper(s, result, path, 0);
        return result;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solve;
    vector<vector<string>> result = solve.partition(s);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        if(i<result.size()-1){
            cout<<endl;
        }
    }
}