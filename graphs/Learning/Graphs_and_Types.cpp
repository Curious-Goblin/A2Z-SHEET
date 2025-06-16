#include<iostream>
#include<math.h>

using namespace std;

long long count(int n) {
    long long edges = (n*(n-1))/2;
    long long count = (long long)pow(2,edges);
    return count;
}

int main(){
    int n;
    cin>>n;
    long long result = count(n);
    cout<<result;
    return 0;
}