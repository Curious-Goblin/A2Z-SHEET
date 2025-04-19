#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'V')
            {
                result += 5;
            }
            else if (s[i] == 'L')
            {
                result += 50;
            }
            else if (s[i] == 'D')
            {
                result += 500;
            }
            else if (s[i] == 'M')
            {
                result += 1000;
            }
            else if (s[i] == 'I')
            {
                if (i < s.size() - 1)
                {
                    if (s[i + 1] == 'V')
                    {
                        result += 4;
                        i++;
                    }
                    else if (s[i + 1] == 'X')
                    {
                        result += 9;
                        i++;
                    }
                    else
                    {
                        result += 1;
                    }
                }
                else
                {
                    result += 1;
                }
            }
            else if (s[i] == 'X')
            {
                if (i < s.size() - 1)
                {
                    if (s[i + 1] == 'L')
                    {
                        result += 40;
                        i++;
                    }
                    else if (s[i + 1] == 'C')
                    {
                        result += 90;
                        i++;
                    }
                    else
                    {
                        result += 10;
                    }
                }
                else
                {
                    result += 10;
                }
            }
            else if (s[i] == 'C')
            {
                if (i < s.size() - 1)
                {
                    if (s[i + 1] == 'D')
                    {
                        result += 400;
                        i++;
                    }
                    else if (s[i + 1] == 'M')
                    {
                        result += 900;
                        i++;
                    }
                    else
                    {
                        result += 100;
                    }
                }
                else
                {
                    result += 100;
                }
            }
        }
        return result;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    int result = solve.romanToInt(s);
    cout << result;
    return 0;
}