#include "bits/stdc++.h"

using namespace std;

bool checkKthBit(int n, int k)
{
    vector<int> bits;
    int temp = n;
    while (temp != 0)
    {
        bits.push_back(temp % 2);
        temp = temp / 2;
    }
    while(bits.size()<=32){
        bits.push_back(0);
    }
    if(bits[k]==1){
        return true;
    }
    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout<<checkKthBit(n,k);
    return 0;
}