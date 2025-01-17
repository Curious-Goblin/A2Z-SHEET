#include "iostream"
#include "vector"
#include "bits/stdc++.h"

using namespace std;

int maxminDist(vector<int> &stalls, int c)
{
    sort(stalls.begin(), stalls.end());
    int cow = 0, no = c, min, low = 0, high, mid;
    high = stalls[stalls.size() - 1]-stalls[0];
    while (low <= high)
    {
        mid = (low + high) / 2;
        cow = 0, no = c - 1;
        for (int j = 1; j < stalls.size(); j++)
        {
            if (no == 0)
            {
                break;
            }
            else if (stalls[j] - stalls[cow] >= mid)
            {
                cow = j;
                no--;
            }
            else
            {
                continue;
            }
        }
        if (no != 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    int t, n, c;
    cin >> t;
    while (t != 0)
    {
        cin >> n >> c;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stalls[i];
        }
        int result = maxminDist(stalls, c);
        cout << result;
        t--;
    }
    return 0;
}