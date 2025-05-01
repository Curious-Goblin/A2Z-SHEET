#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution{
    public:
    // O(n + 1 + n)
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long int xorAll = 0,num = 0,xor1 = 0,xor2 = 0;
        for(long long int i=0;i<N;i++){
            xorAll ^= Arr[i];
        }
        bitset<64> binary(xorAll);
        long long int index=0;
        for(int i=0;i<64;i++){
            if(binary[i]==1){
                index = i;
                break;
            }
        }
        num = 1 << index;
        // num = xorAll & ~(xorAll - 1);
        for(int i=0;i<N;i++)
        {
            if(Arr[i] & num)
            {
                xor1 ^= Arr[i];
            }
            else
            {
                xor2 ^= Arr[i];
            }
        }
        vector<long long int> result;
        if(xor1>=xor2){
            result = {xor1,xor2};
        }
        else{
            result = {xor2,xor1};
        }
        return result;
    }
};

int main(){
    long long int n;
    cin>>n;
    long long int Arr[n];
    for(int i=0;i<n;i++){
        cin>>Arr[i];
    }
    Solution s;
    vector<long long int> result = s.twoOddNum(Arr, n);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}