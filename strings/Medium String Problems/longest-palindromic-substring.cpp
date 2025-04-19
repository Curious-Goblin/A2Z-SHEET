#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // bool isPalindrome(const string &str)
    // {
    //     int l = 0, r = str.size() - 1;
    //     while (l < r)
    //     {
    //         if (str[l++] != str[r--])
    //             return false;
    //     }
    //     return true;
    // }

    // O(n*3)
    // string longestPalindrome(string s)
    // {
    //     string longestPla = "";
    //     int substrLen = 0, len = 0, maxLen = 0;
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = i; j < s.size(); j++)
    //         {
    //             substrLen = (j - i + 1);
    //             bool isPal = isPalindrome(s.substr(i, substrLen));
    //             if (isPal)
    //             {
    //                 len = substrLen;
    //                 if (len > maxLen)
    //                 {
    //                     longestPla = s.substr(i, j - i + 1);
    //                 }
    //                 maxLen = max(maxLen, len);
    //             }
    //         }
    //     }
    //     return longestPla;
    // }

    pair<int, int> palindromeAroundIt(string s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--, right++;
        }
        // because here left and right are one step far from the palindrome;
        return {left + 1, right - 1};
    }
    // O(N*2)
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = palindromeAroundIt(s, i, i);
            auto [left2, right2] = palindromeAroundIt(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                end = right1;
                start = left1;
            }
            if (right2 - left2 > end - start)
            {
                end = right2;
                start = left2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    string result = solve.longestPalindrome(s);
    cout << result;
    return 0;
}