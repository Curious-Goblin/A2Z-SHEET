#include "bits/stdc++.h"

using namespace std;

bool isPowerOfTwo(int n)
{
    // little optimal
    // vector<int> bits;
    // bitset<4> binary(n);
    // cout<<binary<<endl;
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

    // optimal approach

    int ans = n & (n - 1);
    return ans == 0 ? true : false;

    // brute force
    // if(n==0){
    //     return false;
    // }
    // double ans = log2(n);
    // if (ans == floor(ans))
    // {
    //     return true;
    // }
    // return false;
}

int main()
{
    int n;
    cin >> n;
    cout << isPowerOfTwo(n);
    return 0;
}