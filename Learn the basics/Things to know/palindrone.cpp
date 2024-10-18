#include <bits/stdc++.h>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    string result;

    for (char& c : s)
    {
        c = tolower(c);
    }

    for (char& c : s)
    {
        if (isalnum(c))
        {
            result += c;
        }
    }
    
    int len = result.length();
    if (len == 0) return true; 

    std::string::iterator it1 = result.begin();
    std::string::iterator it2 = result.end() - 1; 

    while (it1 < it2) 
    {
        if (*it1 != *it2)
        {
            return false;
        }
        it1++;
        it2--;
    }
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << (isPalindrome(s) ? "true" : "false") << endl;
    return 0;
}
