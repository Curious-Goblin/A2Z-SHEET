#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    string removeKdigits(string num, int k) {
        stack<char> smallestNum;
        // O(2N)
        for(int i=0;i<num.size();i++){
            while(!smallestNum.empty() && (smallestNum.top()-'0')>(num[i]-'0') && k>0){
                smallestNum.pop();
                --k;
            }
            smallestNum.push(num[i]);
        }

        while(k>0){
            smallestNum.pop();
            --k;
        }
        num = "";
        while(!smallestNum.empty()){
            num += smallestNum.top();
            smallestNum.pop();
        }
        // O(N)
        reverse(num.begin(),num.end());
        int i=0;
        while(num[i]=='0'){
            i++;
        }
        num = num.substr(i,num.size()-i);
        if(num == ""){
            num = "0";
        }
        return num;
    }
};

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    Solution solve;
    string result = solve.removeKdigits(s,k);
    cout<<result;
    return 0;
}