#include "bits/stdc++.h"

using namespace std;

int countSetBits(int n)
{
    int temp = 0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = i;
        while (temp > 0)
        {
            if (temp % 2 == 1)
            {
                count++;
            }
            temp = temp / 2;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countSetBits(n);
    return 0;
}