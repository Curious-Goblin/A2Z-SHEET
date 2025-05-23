#include "bits/stdc++.h"

using namespace std;

// long long power(long long base, long long exp, long long mod)
// {
//     long long result = 1;
//     while (exp > 0)
//     {
//         if (exp % 2 == 1)
//         {
//             result = (result * base) % 1000000007;
//             exp = exp - 1;
//         }
//         else
//         {
//             base = (base * base) % 1000000007;
//             exp = exp / 2;
//         }
//     }
//     return result;
// }

// int countGoodNumbers(long long n)
// {
//     long long evenVal = power(5, (n + 1) / 2, 1000000007);
//     long long oddVal = power(4, n / 2, 1000000007);
//     return (evenVal * oddVal) % 1000000007;
// }

// time complexity O(logN) space complexity O(logN) 

long long power(long long base, long long exp, long long mod, long long result)
{
    if(exp==0){
        return result%mod;
    }
    if(exp%2==1){
        return power(base, exp-1, mod, (result*base)%mod);
    }
    else{
        return power((base*base)%mod, exp/2, mod, result);
    }

}

int countGoodNumbers(long long n)
{
    long long evenVal = power(5, (n + 1) / 2, 1000000007,1);
    long long oddVal = power(4, n / 2, 1000000007,1);
    return (evenVal * oddVal) % 1000000007;
}

int main()
{
    long long n;
    int ans;
    cin >> n;
    ans = countGoodNumbers(n);
    cout << ans;
}