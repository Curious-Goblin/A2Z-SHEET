#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:

    // time complexity is given by nth catalan number O(Cn)
    // where Cn is (2n)!/(n!(n+1)!) = (4^n)/(root n);
    // space complexity is O(2n * Cn) each string is of 2n length and 
    // there are total such strings which are equal to Cn
    void helper(vector<string> &paranthesis, string s, int open, int close){
        if(open == 0 && close == 0){
            paranthesis.push_back(s);
            return;
        }
        if(open>0){
            helper(paranthesis,s+'(',open-1,close);
        }
        if(close > open){
            helper(paranthesis,s+')',open,close-1);
        }
    }
    vector<string> generateParanthesis(int n){
        string s="";
        vector<string> paranthesis;
        helper(paranthesis,s,n,n);
        return paranthesis;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    vector<string> result = s.generateParanthesis(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}