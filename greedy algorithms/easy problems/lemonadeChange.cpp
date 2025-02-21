#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int count5 = 0, count10 = 0, count20 = 0;
        for (int i = 0; i < bills.size(); i++)
        {
            bills[i] == 5 ? count5++ : bills[i] == 10 ? count10++
                                                      : count20++;
            if (bills[i] == 5)
            {
                continue;
            }
            else if (bills[i] == 10)
            {
                if (count5 >= 1)
                {
                    count5--;
                }
                else
                {
                    return false;
                }
            }
            else if (bills[i] == 20)
            {
                if (count5 >= 1 && count10 >= 1)
                {
                    count5--;
                    count10--;
                }
                else if (count5 >= 3)
                {
                    count5 = count5 - 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
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
    solve.lemonadeChange(bills) == 1 ? cout << "true" : cout << "false";
    return 0;
}