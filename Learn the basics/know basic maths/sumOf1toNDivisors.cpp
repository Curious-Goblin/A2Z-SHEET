#include "bits/stdc++.h"

using namespace std;

int sumOfDivisors(int n)
{
    int sum = 0, num = n;
    for (int i = 1; i <= num; i++)
    {
        // if (num % i == 0)
        // {
        //     sum += i;
        //     if (num / i != i)
        //     {
        //         sum += (num / i);
        //     }
        // }
        sum += (num / i) * i;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDivisors(n);
}