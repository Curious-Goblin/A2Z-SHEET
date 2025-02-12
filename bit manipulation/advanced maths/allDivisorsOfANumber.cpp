#include "bits/stdc++.h"

using namespace std;

void print_divisors(int n)
{
    map<int, int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert({i, 0});
            if (i != n / i)
            {
                divisors.insert({n / i, 0});
            }
        }
    }
    for (auto &i : divisors)
    {
        cout << i.first << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    print_divisors(n);
    return 0;
}