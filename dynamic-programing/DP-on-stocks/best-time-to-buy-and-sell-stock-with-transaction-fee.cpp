#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int spaceOptimized(vector<int>& prices, int fee){
        int n = prices.size();
        vector<int> curr(2, 0), next(2,0);
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy) curr[buy] = max(next[1], -prices[i] - fee +next[0]);
                else curr[buy] = max(next[0], prices[i] + next[1]);
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return spaceOptimized(prices, fee);
    }
};

int main(){
    int n,fee;
    cin>>n>>fee;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution sol;
    cout<<sol.maxProfit(nums, fee);
    return 0;
}