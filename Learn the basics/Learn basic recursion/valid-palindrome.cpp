#include <iostream>
#include <string>

using namespace std;

bool validPalindrome(string &s, int left, int right){
    if(left >= right){
        return true;
    }
    if(s[left]==s[right]){
        validPalindrome(s,left+1,right-1);
    }
    else{
        return false;
    }
}

int main(){
    string s;
    cin>>s;
    cout<<validPalindrome(s,0,s.size()-1);
    return 0;
}