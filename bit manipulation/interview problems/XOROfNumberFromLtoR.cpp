#include "bits/stdc++.h"

using namespace std;

int xorFromZero(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}

int findXOR(int l, int r)
{
   return xorFromZero(r)^xorFromZero(l-1);
}

int main()
{
    int l, r;
    cin >> l >> r;
    return 0;
}