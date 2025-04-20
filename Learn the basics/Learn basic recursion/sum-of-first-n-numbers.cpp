#include <iostream>

using namespace std;

int recursion(int n, int &sum){
    if(n==0){
        return sum;
    }
    sum +=n;
    recursion(n-1,sum);
}

int main(){
    int n;
    cin>>n;
    int sum=0;
    cout<<recursion(n,sum)<<endl;
    return 0;
}