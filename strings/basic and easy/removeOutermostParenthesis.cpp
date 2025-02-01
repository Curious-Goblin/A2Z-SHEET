#include "iostream"
#include "string"
#include "stack"

using namespace std;

string removeOuterParentheses(string s)
{
    string result = "";
    int balance = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (balance > 0)
            {
                result += s[i];
            }
            balance++;
        }
        else if (s[i] == ')')
        {
            balance--;
            if (balance > 0)
            {
                result += s[i];
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    string result = removeOuterParentheses(s);
    cout << result;
    return 0;
}