#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int spaceOptimized(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1,0)), next(2, vector<int>(k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=k;count++){
                    if(buy){
                        curr[buy][count] = max(-prices[i] + next[0][count], next[1][count]);
                    }
                    else {
                        if(count > 0){
                            curr[buy][count] = max(prices[i] + next[1][count-1], next[0][count]);
                        }
                        else{
                            curr[buy][count] = next[0][count];
                        }
                    }
                }
            }
            next = curr;
        }
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return spaceOptimized(prices, k);
    }
};

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.maxProfit(k, nums);
    return 0;
}