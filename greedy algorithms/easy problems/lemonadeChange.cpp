#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> bills(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bills[i];
    }
    Solution solve;
    cout << solve.lemonadeChange(bills) ? "true" : "false";
    return 0;
}