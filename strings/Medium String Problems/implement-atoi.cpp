#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;
        long ans = 0;
        while (i < s.length() && s[i] == ' ')
            i++;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
            i++;
        while (i < s.length())
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT32_MAX && sign == -1)
                    return INT32_MIN;
                else if (ans > INT32_MAX && sign == 1)
                    return INT32_MAX;
                i++;
            }
            else
                return ans * sign;
        }
        return (ans * sign);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    int result = solve.myAtoi(s);
    cout << result;
    return 0;
}