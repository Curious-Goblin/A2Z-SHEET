#include "bits/stdc++.h"

using namespace std;

vector<int> AllPrimeFactors(int N)
{
    int temp = N, divisor = 2;
    map<int, int> result;
    vector<int> primeFactor;
    while (temp > 1)
    {
        while (temp % divisor == 0)
        {
            result.insert({divisor, 0});
            temp /= divisor;
        }
        divisor++;
        if (divisor * divisor > temp)
        {
            if (temp > 1)
            {
                result.insert({temp, 0});
                break;
            }
        }
    }
    for (auto &i : result)
    {
        primeFactor.push_back(i.first);
    }
    return primeFactor;
}

int main()
{
    int n;
    cin >> n;
    vector<int> result = AllPrimeFactors(n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}