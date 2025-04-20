#include <iostream>

using namespace std;

void recursion(int n){
    if(n==0){
        return;
    }
    int nums = n;
    recursion(n-1);
    cout<<nums<<endl;
}

int main(){
    int n;
    cin>>n;
    recursion(n);
    return 0;
}