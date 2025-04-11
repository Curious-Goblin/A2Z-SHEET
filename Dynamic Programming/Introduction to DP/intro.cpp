#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long int dp[10001];
    long long int MOD = 1e9 + 7;
    Solution()
    {
        for (int i = 0; i <= 10000; ++i)
            dp[i] = -1;
    }
    long long int topDown(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = (topDown(n - 1) + topDown(n - 2)) % MOD;
    }
    long long int bottomUp(int n)
    {
        vector<long long int> dprog(n + 1, -1);
        dprog[0] = 0, dprog[1] = 1;
        for (long long int i = 2; i <= n; i++)
        {
            dprog[i] = (dprog[i - 1] + dprog[i - 2]) % MOD;
        }
        return dprog[n];
    }
};

int main()
{
    int n;
    cin >> n;
    Solution s;
    long long int resT = s.topDown(n);
    long long int resB = s.bottomUp(n);
    cout << resT << endl
         << resB;
    return 0;
}