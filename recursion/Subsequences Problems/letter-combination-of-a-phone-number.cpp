#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution{
    public:

    // time complexity is O(4^n) becuase at most for 7 and 9 we will have 4 options to select
    // space complexity is O(n + 4^n)
    void helper(string digits, string &path, vector<string> &result, int index, unordered_map<char, string> &digitString){
        if(index == digits.size()){
            result.push_back(path);
            return;
        }
        for(char c: digitString[digits[index]])
        {
            path.push_back(c);
            helper(digits, path, result, index+1, digitString); 
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits){
        unordered_map<char, string> digitString = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> result;
        if(digits.empty()) return result;
        string path;
        helper(digits, path, result, 0, digitString);
        return result;
    }
};

int main(){
    string digits;
    cin>>digits;
    Solution s;
    vector<string> result = s.letterCombinations(digits);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}