#include "iostream"
#include "vector"
#include "numeric"
#include "cmath"
#include "bits/stdc++.h"

using namespace std;

long long int minEatingSpeed(vector<long long int> &piles, long long int h)
{
    long long int minSpeed = 0;
    long long int low = 1, high = 1000000000, mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        long long int time = 0;
        for (long long int i = 0; i < piles.size(); i++)
        {
            if (piles[i] <= mid)
            {
                time = time + 1;
            }
            else
            {
                double result = static_cast<double>(piles[i]) / mid;
                time = time + static_cast<long long int>(ceil(result));
            }
        }
        if (time <= h)
        {
            high = mid - 1;
        }
        if (time > h)
        {
            low = mid + 1;
        }
    }
    minSpeed = low;
    return minSpeed;
}

int main()
{
    long long int n, h;
    cin >> n >> h;
    vector<long long int> piles(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> piles[i];
    }
    long long int result = minEatingSpeed(piles, h);
    cout << result;
    return 0;
}