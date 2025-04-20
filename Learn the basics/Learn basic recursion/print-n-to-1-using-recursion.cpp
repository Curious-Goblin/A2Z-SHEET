#include <iostream>

using namespace std;

void recursion(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    recursion(n-1);
}

int main(){
    int n;
    cin>>n;
    recursion(n);
    return 0;
}