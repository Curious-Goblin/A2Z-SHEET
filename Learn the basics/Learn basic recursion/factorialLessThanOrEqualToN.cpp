#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    vector<long long> factorialNumbers(long long n)
    {
        long long temp = 1, i = 2;
        vector<long long> result;
        while (temp <= n)
        {
            result.push_back(temp);
            temp *= i;
            i++;
        }
        return result;
    }
};