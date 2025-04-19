#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // O(N)
    int maxDepth(string s)
    {
        int count = 0, maxcount = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                count--;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution solve;
    int result = solve.maxDepth(s);
    cout << result;
    return 0;
}