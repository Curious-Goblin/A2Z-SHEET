// in the same was just take a stack whenever we see an alphabet or digit we push it into the stack and
// when we see an operator we take out the first two elements from the stack put the operator in between
// them (top1 operator top2) wrap it around the brackets and push it back to the stack;

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
    public:
    // time complexity O(n) + O(n)  
      string preToInfix(string pre_exp) {
        stack<string> infix;
        string s1,s2,s3;
        for(int i=pre_exp.size()-1;i>=0;i--){
            if(isdigit(pre_exp[i]) || isalpha(pre_exp[i])){
                infix.push(pre_exp.substr(i,1));
            }
            else{
                s2 = infix.top();
                infix.pop();
                s1 = infix.top();
                infix.pop();
                // O(n1) + o(n2);
                s3 = "(" + s2 + pre_exp[i] + s1 + ")";
                infix.push(s3);
            }
        }
        return infix.top();
      }
  };

int main(){
    string pre_exp;
    getline(cin,pre_exp);
    Solution s;
    cout<<s.preToInfix(pre_exp);
    return 0;
}