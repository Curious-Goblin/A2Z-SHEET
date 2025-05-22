#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        for(char &c:s){
            if(c=='('){
                low++,high++;
            }
            else if(c==')'){
                low--,high--;
            }
            else if(c=='*'){
                low--,high++;
            }
            if(low < 0) low = 0;
            if(high < 0) return false; 
        }
        if(low == 0) return true;
        return false;
    }
};

int main(){
    string s;
    cin>>s;
    Solution solve;
    cout<<solve.checkValidString(s);
    return 0;
}