#include "bits/stdc++.h"

using namespace std;

int singleNumber(vector<int>& nums) { 
    int ans =0;
    for(auto x:nums){
        ans ^=x;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<singleNumber;
    return 0;
}