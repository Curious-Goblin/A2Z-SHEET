#include "bits/stdc++.h"

using namespace std;

// int setBit(int n)
// {
//     vector<int> bits;
//     int temp = n;
//     while (n > 0)
//     {
//         bits.push_back(n % 2);
//         n = n / 2;
//     }
//     bits.push_back(0);
//     for (int i = 0; i < bits.size(); i++)
//     {
//         if (bits[i] == 0)
//         {
//             n = temp + (int)pow(2, i);
//             return n;
//         }
//     }
//     return n;
// }

// n+1 set the rightmost unset bit to 1 and it also resets all the 1s after it to 0,
// then doing or we get those 1s back but this time with that bit reset.
int setBit(int n)
{
    return n | (n+1);
}

int main()
{
    int n;
    cin >> n;
    cout << setBit(n);
    return 0;
}