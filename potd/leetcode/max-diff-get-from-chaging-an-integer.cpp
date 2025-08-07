#include "bits/stdc++.h"
// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/?envType=daily-question&envId=2025-06-15
using namespace std;

class Solution{
    public:
    int maxDiff(int num){
        string s = to_string(num);
        string maxS = s;
        char toReplace = ' ';
        for(char ch:s){
            if(ch!='9'){
                toReplace = ch;
                break;
            }
        }

        if(toReplace != ' '){
            for(char &ch:maxS){
                if(ch==toReplace){
                    ch = '9';
                }
            }
        }

        int max = stoi(maxS);

        string minS = s;
        if (s[0] != '1') {
            toReplace = s[0];
            for (char &ch : minS) 
            {
                if (ch == toReplace) ch = '1';
            }
        } 
        else {
            toReplace = ' ';
            for (int i = 1; i < minS.size(); i++) {
                if (minS[i] != '0' && minS[i] != '1') {
                    toReplace = minS[i];
                    break;
                }
            }
            if (toReplace != ' ') {
                for (char &ch : minS) {
                    if (ch == toReplace) ch = '0';
                }
            }
        }

        int min = stoi(minS);

        return max - min;
    }
};

int main(){
    int num;
    cin>>num;
    Solution sol;
    cout<<sol.maxDiff(num)<<endl;
    return 0;
}