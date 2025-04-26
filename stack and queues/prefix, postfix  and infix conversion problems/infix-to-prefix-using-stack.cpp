// There are three steps to follow
// 1. reverse the given infix string and replace '(' with ')' and ')' with '('
// 2. do the infix to postfix conversion with a modification that whenever you see a operator other that ^ you push it into the stack.
// 3. do the reverse of the obtained postfix conversion;

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>

using namespace std;

class Solution{
    public:
    int precedence(char c){
        if(c=='^') return 3;
        if(c=='*' || c=='/') return 2;
        if(c=='+' || c=='-') return 1;
        return -1;
    }

    // time complexity 2 reverse = 2*O(n/2), O(2n)
    string infixToPrefix(string &infix_exp){
        reverse(infix_exp.begin(),infix_exp.end()); 
        for(int i=0;i<infix_exp.size();i++){
            if(infix_exp[i]=='('){
                infix_exp[i]=')';
            }
            else if(infix_exp[i]==')'){
                infix_exp[i]='(';
            }
        }
        string output="";
        stack<char> operators;
        for(int i=0;i<infix_exp.size();i++){
            if(isdigit(infix_exp[i]) || isalpha(infix_exp[i])){
                output+=infix_exp[i];
            }
            else if(infix_exp[i]=='('){
                operators.push(infix_exp[i]);
            }
            else if(infix_exp[i]==')'){
                while(!operators.empty() && operators.top()!='('){
                    output+=operators.top();
                    operators.pop();
                }
                operators.pop();
            }
            else{
                if(infix_exp[i]=='^') {
                    while(!operators.empty() && precedence(infix_exp[i])<=precedence(operators.top())){
                        output+=operators.top();
                        operators.pop();
                    }
                }
                else {
                    while(!operators.empty() && precedence(infix_exp[i])<precedence(operators.top())){
                        output+=operators.top();
                        operators.pop();
                    }
                }
                operators.push(infix_exp[i]);
            }        
        }
        while(!operators.empty()){
            output+=operators.top();
            operators.pop();
        }
        reverse(output.begin(),output.end());
        return output;
    }
};

int main(){
    string infix_exp;
    getline(cin, infix_exp);
    Solution s;
    string result = s.infixToPrefix(infix_exp);
    cout<<result;
}