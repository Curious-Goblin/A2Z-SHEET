#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n,1);
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i]){
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }

        int res = 0;
        vector<int> dp2(n,1);
        for(int i=n-1;i>=0;i--){
            for(int prev = n-1;prev>i;prev--){
                if(nums[prev] < nums[i]){
                    dp2[i] = max(dp2[i], 1 + dp2[prev]);
                }
            }
            if(dp1[i] != 1 && dp2[i] != 1){
                res = max(res, dp1[i]+dp2[i]-1);
            }
        }

        return res;
    }
};


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.LongestBitonicSequence(n, nums);
    return 0;
}