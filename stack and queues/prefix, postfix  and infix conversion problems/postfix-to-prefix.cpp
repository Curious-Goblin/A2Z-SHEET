// in the same was just take a stack whenever we see an alphabet or digit we push it into the stack and
// when we see an operator we take out the first two elements from the stack put the operator
// like this (operator + top2 + top1) and push it back to the stack;

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
    public:
    // time complexity O(n) + O(n)  
      string postToPre(string post_exp) {
        stack<string> prefix;
        string s1,s2,s3;
        for(int i=0;i<post_exp.size();i++){
            if(isdigit(post_exp[i]) || isalpha(post_exp[i])){
                prefix.push(post_exp.substr(i,1));
            }
            else{
                s2 = prefix.top();
                prefix.pop();
                s1 = prefix.top();
                prefix.pop();
                // O(n1) + o(n2);
                s3 =  post_exp[i] + s1 + s2;
                prefix.push(s3);
            }
        }
        return prefix.top();
      }
  };

int main(){
    string post_exp;
    getline(cin,post_exp);
    // cin>>post_exp;
    Solution s;
    cout<<s.postToPre(post_exp);
    return 0;
}