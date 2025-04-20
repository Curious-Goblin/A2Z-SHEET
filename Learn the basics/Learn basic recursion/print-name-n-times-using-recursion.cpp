#include <iostream>
#include <string>

using namespace std;

void recursion(int n, string name){
    if(n==0){
        return;
    }
    cout<<name<<endl;
    recursion(n-1,name);
}

int main(){
    int n;
    cin>>n;
    string name;
    cin>>name;
    recursion(n,name);
    return 0;
}