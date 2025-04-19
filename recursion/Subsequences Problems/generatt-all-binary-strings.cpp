#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
    void helper(vector<string> &binaryStrings, string s, int n){
        if(s.length()==n){
            binaryStrings.push_back(s);
            return;
        }

        helper(binaryStrings,s+'0',n);

        if(s.empty()|| s.back()=='0'){
            helper(binaryStrings,s+'1',n);
        }
    }
    vector<string> generateBinaryStrings(int n){
        string s="";
        vector<string> binaryStrings;
        helper(binaryStrings,s,n);
        return binaryStrings;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    vector<string> result = s.generateBinaryStrings(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}