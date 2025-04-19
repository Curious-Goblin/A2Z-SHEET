#include "bits/stdc++.h"

using namespace std;

double myPow(double x, int n) {
    if(n==0){
        return 1;
    }
    if(n<0){
        long long num = -1*n;
        if(num%2==0){
            return 1/myPow(x*x,num/2);
        }
        else {
            return 1/x*myPow(x,num-1);
        }
    }
    if(n%2==0){
        return myPow(x*x,n/2);
    }
    else {
        return x*myPow(x,n-1);
    }
    // double ans = 1.0;
    // long long num = n;
    // if(num<0) num = -1*num;
    // while(num>0){
    //     if(num%2==0){
    //         x=x*x;
    //         num=num/2;
    //     }
    //     else {
    //         ans = ans * x;
    //         num = num-1;
    //     }
    // }
    // if(n<0) ans = (double)1.0/(double)ans;
    // return ans;
}

int main(){
    double x;
    int n;
    cin>>x>>n;
    double result = myPow(x,n);
    cout<<result;
    return 0;
}