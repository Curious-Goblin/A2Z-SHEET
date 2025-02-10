#include "bits/stdc++.h"

using namespace std;

bool isPowerOfTwo(int n)
{
    // vector<int> bits;
    // int temp = n, count = 0;
    // while (temp != 0)
    // {
    //     bits.push_back(temp % 2);
    //     if (temp % 2 == 1)
    //     {
    //         count++;
    //     }
    //     temp = temp / 2;
    // }
    // if (count == 1)
    // {
    //     return true;
    // }
    // return false;
    if(n==0){
        return false;
    }
    double ans = log2(n);
    if (ans == floor(ans))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}