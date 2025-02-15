#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evenlyDivides(int n)
    {
        int digit = 0;
        int count = 0;
        int num = n;
        while (num > 0)
        {
            digit = num % 10;
            if (digit != 0)
            {
                if (n % digit == 0)
                {
                    count++;
                }
            }
            num = num / 10;
        }
        return count;
    }
    
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    int ans = sol.evenlyDivides(n);
    cout << ans;
}