#include "bits/stdc++.h"

using namespace std;

int setBit(int n)
{
    vector<int> bits;
    int temp = n;
    while (n > 0)
    {
        bits.push_back(n % 2);
        n = n / 2;
    }
    bits.push_back(0);
    for (int i = 0; i < bits.size(); i++)
    {
        if (bits[i] == 0)
        {
            n = temp + (int)pow(2, i);
            return n;
        }
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << setBit(n);
    return 0;
}