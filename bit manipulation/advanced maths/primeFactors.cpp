#include "bits/stdc++.h"

using namespace std;

// vector<int> AllPrimeFactors(int N)
// {
//     int temp = N, divisor = 2;
//     map<int, int> result;
//     vector<int> primeFactor;
//     while (temp > 1)
//     {
//         while (temp % divisor == 0)
//         {
//             result.insert({divisor, 0});
//             temp /= divisor;
//         }
//         divisor++;
//         if (divisor * divisor > temp)
//         {
//             if (temp > 1)
//             {
//                 result.insert({temp, 0});
//                 break;
//             }
//         }
//     }
//     for (auto &i : result)
//     {
//         primeFactor.push_back(i.first);
//     }
//     return primeFactor;
// }

vector<int> AllPrimeFactors(int N)
{
    vector<int> result;
    int count = 0;
    while((N & 1)==0){
        count = 1;
        N>>=1;
    }
    if(count == 1){
        result.push_back(2);
    }
    for(int i=3;i<=sqrt(N);i = i+2){
        count = 0;
        while(N%i==0){
            count = 1;
            N/=i;
        }
        if(count == 1){
            result.push_back(i);
        }
    }
    if(N>1){
        result.push_back(N);
    }
    return result;
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