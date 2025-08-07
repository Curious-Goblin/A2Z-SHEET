#include "bits/stdc++.h"

using namespace std;

class Solution{
    public:
    int maximumDifference(vector<int>& nums) {
        int g = nums[nums.size()-1], diff = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<g){
                diff = max(diff, g - nums[i]);
            }
            g = max(g, nums[i]);
        }
        return diff;
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
    cout<<sol.maximumDifference(nums);
}