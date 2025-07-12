#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n,0);
        vector<int> result;
        for(int i=0;i<n;i++){
            hash[i] = i;
        }
        sort(nums.begin(), nums.end());
        int res = 1,id=0;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                    if(dp[i] == 1+dp[prev]){
                        hash[i] = prev;
                    }
                }
            }
            if (dp[i] > res) {
                res = dp[i];
                id = i;
            }
        }
        while(hash[id]!=id){
            result.push_back(nums[id]);
            id = hash[id];
        }
        result.push_back(nums[id]);
        reverse(result.begin(), result.end());
        return result;
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
    vector<int> result = sol.largestDivisibleSubset(nums);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}