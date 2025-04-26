#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parenthesis;
        for (int i = 0; i < s.size(); i++)
        {
            if (parenthesis.empty())
            {
                parenthesis.push(s[i]);
                continue;
            }
            else if (parenthesis.top() == '(')
            {
                if (s[i] == ')')
                {
                    parenthesis.pop();
                    continue;
                }
            }
            else if (parenthesis.top() == '{')
            {
                if (s[i] == '}')
                {
                    parenthesis.pop();
                    continue;
                }
            }
            else if (parenthesis.top() == '[')
            {
                if (s[i] == ']')
                {
                    parenthesis.pop();
                    continue;
                }
            }
            parenthesis.push(s[i]);
        }
        return parenthesis.empty();
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    bool result = solve.isValid(s);
    result == 1 ? cout<<"true" : cout<<"false";
    return 0;
}