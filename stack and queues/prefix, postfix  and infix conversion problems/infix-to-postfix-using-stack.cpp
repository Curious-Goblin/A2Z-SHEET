#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
    public:

    int precedence(char c){
        if(c=='^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        return 0;
    }

    bool isRightAssociative(char c){
        return c == '^';
    }

    string infixToPostfix(string &s){
        string output;
        stack<char> operators;
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                output += s[i];
            }
            else if(s[i]=='('){
                operators.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!operators.empty() && operators.top() != '('){
                    output += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
                else {
                    // while(!operators.empty() && operators.top() != '(' && 
                    //      ((precedence(operators.top())>precedence(s[i])) || 
                    //      ((precedence(operators.top())==precedence(s[i])) && 
                    //      !isRightAssociative(s[i])))){
                    while(!operators.empty() && operators.top() != '(' &&
                    precedence(operators.top()) >= precedence(s[i])) 
                    {
                        output += operators.top();
                        operators.pop();
                    }
                    operators.push(s[i]);
                }
        }    
        while(!operators.empty()){
            output += operators.top();
            operators.pop();
        }
        return output;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solve;
    string result = solve.infixToPostfix(s);
    cout<<result;
}