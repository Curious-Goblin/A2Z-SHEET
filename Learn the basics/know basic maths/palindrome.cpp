#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string s = to_string(x);
        int first = 0, end = s.length() - 1;
        while (first <= end)
        {
            if (s[first] == s[end])
            {
                first++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    long long int n;
    cin >> n;
    Solution solve;
    cout << solve.isPalindrome(n);
    return 0;
}