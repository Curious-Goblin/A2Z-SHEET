#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    // O(nlog(log(n)))
    vector<int> AllPrimeFactors(int N){
        vector<bool> isPrime(N+1, true);
        for(int p = 2; p*p <= N; p++){
            if(isPrime[p]){
                int temp = p*p;
                for(int i=temp;i<isPrime.size();i += p){
                    isPrime[i] = false;
                }
            }
        }
        for(int p = 2;p<=N;p++){
            if(isPrime[p]){
                if(N%p!=0){
                    isPrime[p] = false;
                }
            }
        }
        vector<int> result;
        for(int p = 2;p<isPrime.size();p++){
            if(isPrime[p]){
                result.push_back(p);
            }
        }
        return result;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    vector<int> result = s.AllPrimeFactors(n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}