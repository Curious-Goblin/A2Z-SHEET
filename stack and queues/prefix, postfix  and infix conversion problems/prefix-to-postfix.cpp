// in the same was just take a stack whenever we see an alphabet or digit we push it into the stack and
// when we see an operator we take out the first two elements from the stack put the operator
// like this (top1 + top2 + operator) and push it back to the stack;

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
    public:
    // time complexity O(n) + O(n)  
      string preToPost(string pre_exp) {
        stack<string> postfix;
        string s1,s2,s3;
        for(int i = pre_exp.size()-1;i>=0;i--){
            if(isdigit(pre_exp[i]) || isalpha(pre_exp[i])){
                postfix.push(pre_exp.substr(i,1));
            }
            else{
                s1 = postfix.top();
                postfix.pop();
                s2 = postfix.top();
                postfix.pop();
                // O(n1) + o(n2);
                s3 = s1 + s2 + pre_exp[i];
                postfix.push(s3);
            }
        }
        return postfix.top();
      }
  };

int main(){
    string pre_exp;
    getline(cin,pre_exp);
    // cin>>pre_exp;
    Solution s;
    cout<<s.preToPost(pre_exp);
    return 0;
}