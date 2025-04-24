#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    // O(nlog(log(n)))
    int countPrimes(int n){
        vector<bool> isPrime(n,true);
        for(int p = 2; p*p < n; p++){
            if(isPrime[p]){
                int temp = p*p;
                for(int i=temp;i<isPrime.size();i += p){
                    isPrime[i] = false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<isPrime.size();i++){
            if(isPrime[i]==true){
                count++;
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    int result = s.countPrimes(n);
    cout<<result;
}