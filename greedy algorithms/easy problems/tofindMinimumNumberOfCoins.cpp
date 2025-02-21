#include "bits/stdc++.h"

using namespace std;

class Solution
{

public:
    int minCoins(vector<int> &coins, int sum)
    {
        sort(coins.begin(), coins.end());
        int number = 0, current = 0;
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            if (coins[i] <= sum)
            {
                current = sum / coins[i];
                number = number + current;
                sum = sum - (coins[i] * current);
            }
            else if (sum == 0)
            {
                break;
            }
        }
        if(sum == 0){
            return number;
        }
        return -1;
    }
};

int main()
{
    int sum, s;
    cin >> sum >> s;
    vector<int> coins(s);
    for (int i = 0; i < s; i++)
    {
        cin >> coins[i];
    }
    Solution solve;
    cout << solve.minCoins(coins, sum);
    return 0;
}