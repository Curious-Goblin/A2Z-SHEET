#include "bits/stdc++.h"

using namespace std;

class Solution {
  public:
    //o(n)
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> ropes;
        // o(logn)
        for(auto &r : arr){
            ropes.push(r);
        }

        int cost = 0;
        int newL = 0;
        // o(n)
        while(ropes.size()!=1){
            newL += ropes.top();
            ropes.pop();
            newL += ropes.top();
            ropes.pop();
            ropes.push(newL);
            cost += newL;
            newL = 0;
        }
        return cost;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution s;
    cout<<s.minCost(nums);
    return 0;
}