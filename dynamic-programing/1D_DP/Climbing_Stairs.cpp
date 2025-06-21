#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ways;
    Solution()
    {
        ways = vector<int>(46, 0);
        ways[1] = 1, ways[2] = 2;
    }

    int climbStairs(int n)
    {
        if (n == 2)
        {
            return 2;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 0)
        {
            return 0;
        }
        if (ways[n] != 0)
        {
            return ways[n];
        }
        return ways[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    int result = s.climbStairs(n);
    cout << result;
    return 0;
}