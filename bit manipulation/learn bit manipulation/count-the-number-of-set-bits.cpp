#include <iostream>

using namespace std;

class Solution {
    public:
    // when we subtract 1 then it flips all the bits after the rightmost set bit including that bit so
    // whenever we do n&n-1 we are removing the lowest 1 bit so count how many times we can do it.
    int setBits(int n){
        int count = 0;
        while(n!=0){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    int result = s.setBits(n);
    cout<<result;
    return 0;
}