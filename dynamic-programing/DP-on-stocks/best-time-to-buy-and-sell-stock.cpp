#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int recursion(vector<int>& prices, int id, int buy, int sell){
        if(buy != -1 && sell != -1){
            return sell - buy;
        }
        if(id == prices.size()-1){
            if(buy == -1 && sell == -1) return -1;
            if(sell == -1) return prices[id] - buy;
            return -1;
            
        }
        if(buy!=-1){
            int sale = recursion(prices, id+1, buy, prices[id]);
            int keep = recursion(prices, id+1, buy, sell);
            return max(sale, keep);
        }
        else{
            int take = recursion(prices, id+1, prices[id], sell);
            int skip = recursion(prices, id+1, buy, sell);
            return max(take, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // int res = recursion(prices, 0, -1, -1);
        // if(res < 0) return 0;
        // return res;
        int bought = -1;
        int profit = 0;
        for(auto &val:prices){
            if(bought == -1){
                bought = val;
            }
            else {
                if(val < bought){
                    bought = val;
                }
                else {
                    profit = max(profit,val - bought);
                }
            }
        }
        return profit;
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
    cout<<sol.maxProfit(nums);
    return 0;
}