// in the same was just take a stack whenever we see an alphabet or digit we push it into the stack and
// when we see an operator we take out the first two elements from the stack put the operator in between
// them (top2 operator top1) wrap it around the brackets and push it back to the stack;

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
    public:
    // time complexity O(n) + O(n)  
      string postToInfix(string exp) {
        stack<string> infix;
        string s1,s2,s3;
        for(int i=0;i<exp.size();i++){
            if(isdigit(exp[i]) || isalpha(exp[i])){
                infix.push(exp.substr(i,1));
            }
            else{
                s2 = infix.top();
                infix.pop();
                s1 = infix.top();
                infix.pop();
                // O(n1) + o(n2);
                s3 = "(" + s1 + exp[i] + s2 + ")";
                infix.push(s3);
            }
        }
        return infix.top();
      }
  };

int main(){
    string exp;
    // getline(cin,exp);
    cin>>exp;
    Solution s;
    cout<<s.postToInfix(exp);
    return 0;
}